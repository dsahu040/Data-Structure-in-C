#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}Node;

Node *makenode(int val) {
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}

void insert_list(Node **head, int val) {
    Node *n = makenode(val);

    n->next = *head;
    *head = n;
    return;
}

void print_list(Node *head) {
    Node *walker = head;
    while(walker != NULL) {
        printf("\n%d", walker->val);
        walker = walker->next;
    }
    printf("\n");
    return;
}

void largest(Node *head) {

    if(head != NULL) {

        int max = head->val;
        Node *walker = head;

        while(walker != NULL) {
            if(walker->val > max) {
                max = walker->val;
            }
            walker = walker->next;
        }
        printf("\nlargest element of the list: %d\n", max);
    } else {
            printf("\nThe list is empty.\n");
    }
}

int main(void) {
    Node *head = NULL;
    insert_list(&head, 50);
    insert_list(&head, 6);
    insert_list(&head, 13);
    insert_list(&head, 98);
    insert_list(&head, 49);
    insert_list(&head, 100);

    print_list(head);

    largest(head);
}
