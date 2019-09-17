/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    char* file;
    struct node * next;
}node_p;

bool queue_is_empty(node_p * head) {
    return head == NULL;
}

void dequeue(node_p ** head) {
    if (*head == NULL) {
        printf("FATAL, empty queue\n");
        return;
    }
    node_p *top = *head;
    *head = (*head)->next;
    top->next = NULL;
    free(top->file);
    free(top);

    return;
}

void enqueue(node_p ** head, node_p ** tail, char * file) {
    node_p * new_node= (node_p *)malloc(sizeof(node_p));
    if (!new_node) {
        printf("Out of memory\n");
        return;
    }

    new_node->file = (char *) malloc (strlen(file) + 1);
    if (!new_node->file) {
        printf("Out of memory\n");
        return;
    }

    strcpy(new_node->file, file);

    new_node->next = NULL;
    if (!(*head)) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

char * queue_top(node_p * head) {
    if (!head) {
        printf("queue head is NULL\n");
        return NULL;
    }
    return head->file;
}

int main()
{
    node_p * head = NULL;
    node_p * tail = NULL;
    enqueue(&head, &tail, "abc");
    enqueue(&head, &tail, "bcd");
    enqueue(&head, &tail, "cde");
    dequeue(&head);
    
    dequeue(&head);
    dequeue(&head);

    return 0;
}
