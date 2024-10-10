#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void insert(struct node **head, Task *task) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->task = task;
    newNode->next = *head;
    *head = newNode;
}

void delete(struct node **head, Task *task) {
    struct node *temp = *head;
    struct node *prev = NULL;
    while (temp != NULL && temp->task != task) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
}

void traverse(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("[%s] Priority: %d Burst %d\n", temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}

