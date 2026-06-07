#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void addFirst (struct node **head, int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    newNode->next = *head;
    *head = newNode;
}

