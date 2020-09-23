#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void enqueue(Node **head, int data) {

    Node *node = malloc(sizeof(Node));
    node->data= data;
    node->next = NULL;

    if(*head == NULL) {
        *head = node;
        return;
    }

    Node *walker = *head;
    while(walker->next != NULL){
        walker = walker->next;
    }
    walker->next = node;
    return;
}

void dequeue(Node **head){
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
}

void peek(Node *head) {
    printf("The first element in the queue is: %d\n", head->data);
    return;
}

int size(Node *head) {
    if(head == NULL) {
        return 0;
    }
    return 1 + size(head->next);
}

int isEmpty(Node *head) {
    return head == NULL ? 1 : 0;
}

void print_queue(Node *head) {
    printf("\nQueue: ");
    Node *walker = head;
    while(walker != NULL) {
        printf("\n%d", walker->data);
        walker = walker->next;
    }
    printf("\n");
    return;
}

int main(void) {
    Node *head = NULL;

    enqueue(&head, 5);
    enqueue(&head, 4);
    enqueue(&head, 3);
    enqueue(&head, 2);
    enqueue(&head, 1);
    print_queue(head);
    printf("\nThe size of queue is %d\n", size(head));

    dequeue(&head);
    printf("\nafter dequeue ");
    print_queue(head);

    peek(head);

    if(!isEmpty(head)){
        printf("\nQueue is not empty.");
    }
}
