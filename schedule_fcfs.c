#include <stdio.h>
#include "schedulers.h"
#include "list.h"

void schedule_fcfs(struct node *taskList) {
    struct node *current = taskList;
    while(current != NULL) {
        printf("Running task: [%s] Priority: %d Burst: %d\n",current->task->name, current->task->priority, current->task->burst);
        current = current->next;
    }
}