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

//functions
int menu(struct Node* head);
void printList(struct Node* head);
void push(struct Node** head, int data);
void sortedInsert(struct Node** head, struct Node* newNode);
void insertSort(struct Node** head);
int creating(struct Node* head);


int main(void) {
	struct Node* head = NULL;
	menu(head);

    return 0;
}

void printList(struct Node* head) {
    if(head == NULL) {
        printf("Please create a linear linked list first!");
        return;
    }
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }

    printf("null");
}


void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


void sortedInsert(struct Node** head, struct Node* newNode) {
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


void insertSort(struct Node** head) {
    if(head == NULL) {
        printf("Please create a linear linked list first!");
        return;
    }

    struct Node* result = NULL;     
    struct Node* current = *head;   
    struct Node* next;
 
    while (current != NULL)
    {
        
        next = current->next;
 
        sortedInsert(&result, current);
        current = next;
    }
 
    *head = result;
}

int menu(struct Node* head) {
	    char userChoice;

    printf("\n\ta. Create");
    printf("\n\tb. Display a Linear Linked List");
    printf("\n\tc. Sort a Linear Linked List - Ascending");
    printf("\n\td. Search a number");
    printf("\n\te. Exit\n");

	printf("\n Enter your choice:");
	scanf("%s", &userChoice);
	fgetc(stdin);


    if(userChoice == 'a' || userChoice == 'A') {
        creating(head);
    } else if(userChoice == 'b' || userChoice == 'B') {
        printList(head);
        menu(head);
    } else if(userChoice == 'c' || userChoice == 'C') {
        insertSort(&head);
        printList(head);
        menu(head);
    } else if(userChoice == 'd' || userChoice == 'D') {
        insertSort(&head);
        printList(head);
        menu(head);
    } else if(userChoice == 'e' || userChoice == 'E') {
        printf("\nPROGRAM TERMINATING...");    
        exit(2);
    } else {
        printf("\nInvalid Input"); 
        menu(head);
    }


    //insertSort(&head);

    // print linked list
    //printList(head);

    return 1;
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
			menu(head);
        }else if(sscanf(userInp, "%d", &keys)) {
            printf("Adding data: %d \n", keys);
            push(&head, keys);
        }
    }
}