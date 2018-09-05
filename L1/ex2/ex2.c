/*************************************
* Lab 1 Exercise 1
* Name:
* Matric No:
* Lab Group:
*************************************/

#include <stdio.h>
#include <stdlib.h> //for malloc() and free()

//Declaration of a Linked List Node

typedef struct NODE{
    int data;
    struct NODE* next;
} node;

//Function Prototypes
node* insertAt(node*, int, int, int);
node* addToHead(node*, int);
void printList(node*);
void destroyList(node*);



int main()
{
    node* myList = NULL;    //Empty List
    int position, input, copy;

    //Fill in code for input and processing
    while (scanf("%i %i %i", &position, &input, &copy) == 3) {
        myList = insertAt(myList, position, copy, input);	
    }
    
    //Output code coded for you
    printf("My List:\n");
    printList(myList);
    
    destroyList(myList);
    myList = NULL;

    
    printf("My List After Destroy:\n");
    printList(myList);
 
    return 0;
}

//Actual Function Implementations
node* insertAt(node* head, int position, int copies, int newValue)
{
    //Fill in your code here
    int currentPos = 0;
    node *currentNode, *prevNode;
    currentNode = (node*) malloc (sizeof (node));
    prevNode = (node*) malloc (sizeof (node));
   
    if (!head) {
	currentNode->data = newValue;
        head = currentNode;
        for(int i=copies-1; i>0; i--) {
	    //printf("in for loop\n");
	    node *newNode;
	    newNode = (node*) malloc (sizeof (node));
            newNode->data = newValue;
	    prevNode->next = newNode;
	    if (i == copies-1) {
	        head->next = newNode;
	    }
            prevNode = newNode;

	}
	return head;
    
    }
    
    currentNode = head;
    while(currentNode) {
        if(currentPos == position) {
	    break;
	}
	prevNode = currentNode;
	currentNode = currentNode->next;
	currentPos++;
    }
 
    //printf("%d", currentPos==position);

    if (currentPos != position) {
        for(int i=copies; i>0; i--) {
            node *newNode;
            newNode = (node*) malloc (sizeof (node));
            newNode->data = newValue;

            prevNode->next = newNode;
	    prevNode = newNode;
	}
    }
    else {
	if (currentPos == 0) {
	    for(int i=copies; i>0; i--) {
	        head = addToHead(head, newValue);
	    }
	}
	else {
            for(int i=copies; i>0; i--) {
                node *newNode;
	        newNode = (node*) malloc (sizeof (node));
	        newNode->data = newValue;
                prevNode->next = newNode;
	        prevNode = newNode;

	    }
	}
	prevNode->next = currentNode;
    }
            

    return head;    //change this!
}

node* addToHead(node* head, int newData)
{
    node *newNode = (node*) malloc (sizeof (node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    return head;    //change this
}

void printList(node* head)
//Purpose: Print out the linked list content
//Assumption: the list is properly null terminated
{
    //This function has been implemented for you
    node* ptr = head;

    while (ptr != NULL)  {    //or you can write while(ptr)
        printf("%i ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void destroyList(node* head)
{
    node* next;
    node* current = head;
    //Fill in your code here
    while (current != NULL) {
        next = current->next;
	free(current);
	current=next;
    }
    //You can use the same implementation as in exercise 1
}
