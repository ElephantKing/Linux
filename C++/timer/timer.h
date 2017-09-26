#ifndef __TIMER_H__
#define __TIMER_H__

#include <time.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>

class Timer
{
public:
        class Observe
        {
        public:
                virtual ~Observe(){}
                virtual void Update() = 0;
        };
private:
        static time_t now;
        static timeval now_tv;
        time_t t;
        timeval tv;

        typedef std::vector<Observe*> observes;
        static observes& Observes()
        {
                static observes temp;
                return temp;
        }
public:
        Timer() : t(now)
        {
                if (!now) now = t = time(NULL);
                if (!timerisset(&now_tv))
                {
                        gettimeofday(&now_tv, NULL);
                        tv.tv_sec = now_tv.tv_sec;
                        tv.tv_usec = now_tv.tv_usec;
                }
        }

        static void Attach(Observe* ob)
        {
                Observes().push_back(ob);
        }

        static void Detach(Observe* ob)
        {
                Observes().erase(std::remove(Observes().begin(), Observes().end(), ob), Observes().end());
        }

        static void Update()
        {
                time_t temp = time(NULL);
                if (temp > now)
                {
                        now = temp;
                        gettimeofday(&now_tv, NULL);
                        std::for_each(Observes().begin(), Observes().end(), std::mem_fun(&Observe::Update));
                }
        }

        static time_t GetTime() { return now; }
        static timeval GetTime_tv() { return now_tv; }

        void Reset()
        {
                t = now;
                tv.tv_sec = now_tv.tv_sec;
                tv.tv_usec = now_tv.tv_usec;
        }

};

#endif
