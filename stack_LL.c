#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void push(Node **head, int data) {

    Node *node = malloc(sizeof(Node));
    if(node == NULL) {
        printf("\n Memory error");
        exit(0);
    }
    node->data = data;
    node->next = *head;
    *head = node;
    return;
}

void pop(Node **head) {
    *head = (*head)->next;
    return;
}

void peek(Node *head) {
    printf("\ntop element in stack is : %d\n", head->data);
}

int size(Node *head) {
    int count = 0;
    Node *walker = head;
    while(walker != NULL) {
        count++;
        walker = walker->next;
    }
    return count;
}

int isEmpty(Node *head) {
    return head == NULL ? 1 : 0;
}

void print_stack(Node *head){

    Node *walker = head;
    while(walker != NULL ) {
        printf("\n%d", walker->data);
        walker = walker->next;
    }
    printf("\n");
    return;
}

int main(void) {
    Node *head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    print_stack(head);
    printf("\nsize of stack : %d", size(head));

    pop(&head);
    printf("\npop one element");
    print_stack(head);

    peek(head);
    printf("\nsize of stack : %d", size(head));
}
