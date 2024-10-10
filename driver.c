#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "cpu.h"

#define SIZE    100

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    struct node *taskList = NULL;

    in = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));
        // add the task to the scheduler's list of tasks
        printf("Task read: Name: %s, Priority: %d, Burst: %d\n", name, priority, burst);
        add(name,priority,burst, &taskList);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    #ifdef FCFS
        schedule_fcfs(taskList);
    #elif defined(SJF)
        schedule_sjf(taskList);
    #elif defined(RR)
        schedule_rr(taskList);
    #elif defined(PRIORITY)
        schedule_priority(taskList);
    #elif defined(PRIORITY_RR)
        schedule_pri_rr(taskList);
    #endif

    return 0;
}
