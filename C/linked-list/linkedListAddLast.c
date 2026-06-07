#include <stdio.h>
#include <stdlib.h>

/*
1. Declare head pointer and make it as NULL.
2. Create a new node with the given data. And make the new node => next as NULL.
   (Because the new node is going to be the last node.)
3. If the head node is NULL (Empty Linked List),
   make the new node as the head.
4. If the head node is not null, (Linked list already has some elements),
   find the last node. make the last node => next as the new node.
*/

struct node {
    int data;
    struct node *next;
};

void addLast(struct node **head, int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

     //if head is NULL, it is an empty list
    if (*head == NULL){
        *head = newNode;
    }
    //Otherwise, find the last node and add the newNode
    else {
        struct node *lastNode = *head;

        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;

    }
}

void printList (struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;

    addLast(&head,10);
    addLast(&head,20);
    addLast(&head,30);

    printList(head);

    return 0;
}