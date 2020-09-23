#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    } Node;

void insert_head(Node **head, Node *node);
void print_list(Node *head);
void insert_list(Node **head, Node *node);
void free_list(Node **head);
void removeNode(Node **head, Node *node);

Node *make_node(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

int main() {
    Node *a = make_node(30);
    Node *b = make_node(25);
    Node *c = make_node(13);

    Node *head = NULL;

    insert_list(&head, b);
    print_list(head);
    insert_list(&head, c);
    print_list(head);
    insert_list(&head, a);
    print_list(head);

    removeNode(&head, a);
    print_list(head);

}

void insert_head(Node **head, Node *node) {
    node->next = *head;
    *head = node;
    return;
}

void print_list(Node *head) {
 Node *walker = head;
 while(walker != NULL) {
    printf("\n%d", walker->value);
    walker = walker->next;
 }
 printf("\n");
 return;
}

void insert_list(Node **head, Node *node) {
  	Node *current;

    if (*head == NULL || (*head)->value >= node->value) {
		node->next = *head;
        *head = node;
    } else {
        current = *head;
		while (current->next!=NULL && current->next->value < node->value) {
			current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
	  return;
}

void removeNode(Node **head, Node *node) {
    if(head == NULL) {
        return;
    }
    if((*head)->value == node->value){
        *head = (*head)->next;
        return;
    }

    Node *walker = *head;
    while(walker->next != NULL) {
        if(walker->next->value == node->value) {
            walker->next = walker->next->next;
        } else {
            walker = walker->next;
        }
    }
}

void free_list(Node **head) {
    Node *reaper = NULL;
    Node *walker = *head;
    while(walker != NULL) {
        printf("/n%d", walker->value);
        reaper = walker;
        walker = walker->next;
        free(reaper);
        reaper = NULL;
    }
    return;
}
