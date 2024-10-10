#include <stdio.h>
#include "schedulers.h"
#include "list.h"
#include "task.h"
#include "cpu.h"

// extern struct node* taskList;

void schedule_fcfs(struct node *taskList) {
    struct node* task_list = taskList;
    if (task_list == NULL) {
        printf("Task list is empty!\n");
        return;
    }

    printf("Starting FCFS scheduling...\n");
    while (task_list != NULL) {
        Task* task = task_list->task;
        printf("Running task: [%s], Priority: [%d], Burst: [%d]\n", task->name, task->priority, task->burst);
        run(task, task->burst); // Simulate running the task
        task_list = task_list->next;
    }
    printf("FCFS scheduling completed.\n");
}
