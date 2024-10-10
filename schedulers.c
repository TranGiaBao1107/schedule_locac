#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedulers.h"
#include "list.h"

struct node *taskList = NULL;

void add(char *name, int priority, int burst, struct node **taskList) {
    Task *newTask = (Task *) malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = priority;
    newTask->burst = burst;
    insert(taskList, newTask);
}