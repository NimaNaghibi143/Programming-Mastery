#include <stdio.h>
#include <stdlib.h>

/*
1. Iterate the linked list using a loop.
2. If any node has the given key value, return 1.
3. If the program execution comes out of 
   the loop (the given key is not present in the linked list), return -1.
*/

struct node {
    int data;
    struct node *next;
};

void addLast(struct node **head, int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next     = NULL;

    if(*head == NULL)
         *head = newNode;
    else
    {
        struct node *lastNode = *head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    }

}

int searchNode(struct node *head, int key) {
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->data == key){
            return 1;
        }
        temp = temp->next;
    }

    return -1;   
}

int main () {
    struct node *head = NULL;

    addLast(&head,10);
    addLast(&head,20);
    addLast(&head,30);

    if(searchNode(head,20) == 1)
         printf("Search Found\n");
     else
        printf("Search Not Found\n");

    return 0;
}