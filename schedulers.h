#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include "list.h"

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void add(char *name, int priority, int burst, struct node **taskList);

// invoke the scheduler
void schedule_fcfs(struct node *taskList);
// void schedule_sjf();
// void schedule_priority();
// void schedule_rr();
// void schedule_pri_rr();

#endif