/*
1. If the head node has the given key,
   make the head node points to the second node and free its memory.
2. Otherwise, From the current node, check whether the next node has the given key
   if yes, make the current->next = current->next->next and free the memory.
   else, update the current node to the next and do the above process (from step 2)
   till the last node.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addLast(struct node **head, int val)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next     = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }

}

void deleteNode(struct node **head, int key) {
    struct node *temp;

    if ((*head)->data == key){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else {
        struct node *currentNode = *head;

        while (currentNode->next != NULL) {
            if (currentNode->next->data == key){
                temp = currentNode->next;

                currentNode->next = currentNode->next->next;
                free(temp);
                break;
            }else {
                currentNode = currentNode->next;
            }
        }
    }
}

void printList(struct node *head)
{
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d ->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
     struct node *head = NULL;

     addLast(&head,10);
     addLast(&head,20);
     addLast(&head,30);
     printf("Linked List Elements:\n");
     printList(head);

     //delete first node
     deleteNode(&head,10);
     printf("Deleted 10. The New Linked List:\n");
     printList(head);

     //delete last node
     deleteNode(&head,30);
     printf("Deleted 30. The New Linked List:\n");
     printList(head);

     //delete 20
     deleteNode(&head,20);
     printf("Deleted 20. The New Linked List:\n");
     printList(head);

     return 0;
}