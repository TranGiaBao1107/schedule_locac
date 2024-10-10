#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"
#include "list.h"
// add task
void add(char *name, int priority, int burst, struct node **taskList);
// define schedules
void schedule_fcfs(struct node *taskList);
void schedule_sjf(struct node *taskList);
void schedule_rr(struct node *taskList, int quantum);
void schedule_priority(struct node *taskList);
void schedule_priority_rr(struct node *taskList, int quantum);

#endif