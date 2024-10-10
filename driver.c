#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE 100

int main(int argc, char *argv[]) {
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;
    struct node *taskList = NULL;
    in = fopen(argv[1], "r");
    if (in == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    while(fgets(task, SIZE, in)!=NULL) {
        temp = strdup(task);
        name = strsep(&temp, ",");
        priority = atoi(strsep(&temp, ","));
        burst = atoi(strsep(&temp,","));
        printf("Task: %s, Priority: %d, Burst: %d\n", name, priority, burst);
        // add task to the scheduler's list
        add(name, priority, burst, &taskList);
        free(temp);
    }
    fclose(in);
    #ifdef FCFS
        schedule_fcfs(taskList);
    #elif defined(SIF)
        schedule_sjf(taskList);
    #elif defined(RR)
        int quantum = 10;
        schedule_rr(taskList, quantum);
    #elif defined(PRIORITY)
        schedule_priority(taskList);
    #elif defined(PRIORITY_RR)
        int quantum = 10;
        schedule_priority_rr(taskList, quantum);
    #endif
    return 0;
}