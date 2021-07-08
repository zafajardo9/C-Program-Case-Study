#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>



struct Node
{
    int data;
    struct Node* next;
};
 

void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("null");
}
 

void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 

void sortedInsert(struct Node** head, struct Node* newNode)
{
    struct Node dummy;
    struct Node* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
 
// Given a list, change it to be in sorted order (using `sortedInsert()`).
void insertSort(struct Node** head)
{
    struct Node* result = NULL;     // build the answer here
    struct Node* current = *head;   // iterate over the original list
    struct Node* next;
 
    while (current != NULL)
    {
        // tricky: note the next pointer before we change it
        next = current->next;
 
        sortedInsert(&result, current);
        current = next;
    }
 
    *head = result;
}

int creating(struct Node* head) {
    int keys;
    char userInp[64];
    while(1) {
        printf("\nEnter a Value: ");
        fgets(userInp, 64, stdin);

        if(strcmp("s\n", userInp) == 0){
            printf("END OF LIST... \n");
            printList(head);
            return 1;
        }else if(sscanf(userInp, "%d", &keys)) {
            printf("Adding data: %d \n", keys);
            push(&head, keys);
        }
    }
}




int main(void) {
    char userChoice;

    printf("\n a. Create");
    printf("\n b. Display a Linear Linked List");
    printf("\n c. Sort a Linear Linked List - Ascending");
    printf("\n d. Search a number");
    printf("\n e. Exit\n");

	printf("\n Enter your choice:");
	scanf("%s", &userChoice);
	fgetc(stdin);

    struct Node* head = NULL;

    if(userChoice == 'a' || userChoice == 'A') {
        creating(head);
    } else if(userChoice == 'b' || userChoice == 'B') {
        printList(head);
    } else if(userChoice == 'c' || userChoice == 'C') {
        insertSort(&head);
        printList(head);
    }

 

    
 
 



    insertSort(&head);
 
    // print linked list
    printList(head);
 
    return 0;
}