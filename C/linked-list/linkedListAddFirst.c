#include <stdio.h>
#include <stdlib.h>

/*
1. Declare a head pointer and make it as NULL.
2. Create a new node with the given data.
3. Make the new node points to the head node.
4. Finally, make the new node as the head node.
*/

struct node {
    int data;
    struct node *next;
};

void addFirst (struct node **head, int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    newNode->next = *head;
    *head = newNode;
}

void printList (struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf ("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

int main () {
    struct node *head = NULL;

    addFirst(&head, 10);
    addFirst(&head, 20);
    addFirst(&head, 30);

    printList(head);

    return 0;
}