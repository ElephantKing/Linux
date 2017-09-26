#include <stdio.h>
#include <string>

#include "timer.h"

class Task : public Timer::Observe
{
public:
        Task()
        {
                Timer::Attach(this);
        }

        void Update()
        {
                printf("timer task\n");
                fflush(stdout);
        }
};

int main()
{
        {
                //get time(seconds) distance from 1970.1.1:00:00:00
                time_t now = time(NULL);
                time_t now_;
                time(&now_);
                printf("now=%ld,now_=%ld\n",now, now_);

                //get time(useconds,1/10^6s) distance from 1970.1.1:00:00:00
                timeval now_tv;
                gettimeofday(&now_tv, NULL);
                printf("now_tv.sec=%ld, now_tv.usec=%ld\n",now_tv.tv_sec,now_tv.tv_usec);
        }
        Task task;
        while(1)
        {
                sleep(1);
                Timer::Update();
        }
        return 0;
}
