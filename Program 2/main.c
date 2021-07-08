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

struct Node* mid_node(struct Node* start, struct Node* last){
    if (start == NULL)
        return NULL;
    struct Node* slow = start;
    struct Node* fast = start -> next;
    while (fast != last){
        fast = fast -> next;
        if (fast != last){
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    return slow;
}
struct Node* binarySearch(struct Node *head, int value){
    struct Node* start = head;
    struct Node* last = NULL;
    do{
        struct Node* mid = mid_node(start, last);
        if (mid == NULL)
            return NULL;
        if (mid -> data == value)
            return mid;
        else if (mid -> data < value)
            start = mid -> next;
        else
            last = mid;
    } while (last == NULL || last != start);
        return NULL;
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
        int int_search;
    puts("\n\ta. Create");
    puts("\n\tb. Display a Linear Linked List");
    puts("\n\tc. Sort a Linear Linked List - Ascending");
    puts("\n\td. Search a number");
    puts("\n\te. Exit\n");

	puts("\n Enter your choice:");
	scanf("%s", &userChoice);
	fgetc(stdin);


    if(userChoice == 'a' || userChoice == 'A') {
        system("cls");
        creating(head);
    } else if(userChoice == 'b' || userChoice == 'B') {
        system("cls");
        printList(head);
        menu(head);
    } else if(userChoice == 'c' || userChoice == 'C') {
        system("cls");
        insertSort(&head);
        printList(head);
        menu(head);
    } else if(userChoice == 'd' || userChoice == 'D') {
        system("cls");
        printf("\nEnter a value to be searched.");
        scanf("%d", &int_search);

        if(binarySearch(head, int_search) == NULL) {
            printf("Value is not present in linked list\n");
        }else {
            printf("Value [%d] is present in linked list\n", int_search);
        }
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
    //printList(head);

    return 1;
}

int creating(struct Node* head) {
    int keys;
    char userInp[64];
    while(1) {
        printf("\nEnter a Value: ");
        printf("\nEnter 's' to stop! : ");
        fgets(userInp, 64, stdin);

        if(strcmp("s\n", userInp) == 0){
            printf("END OF LIST... \n");
            //printList(head);
			menu(head);
        }else if(sscanf(userInp, "%d", &keys)) {
            printf("Adding data: %d \n", keys);
            push(&head, keys);
        }
    }
}

