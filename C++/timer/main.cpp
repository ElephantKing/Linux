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
        Task task;
        while(1)
        {
                sleep(1);
                Timer::Update();
        }
        return 0;
}
