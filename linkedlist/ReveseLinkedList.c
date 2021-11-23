#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

static void reverse (struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* curr = *head_ref;
    struct Node* next = NULL;
    // Its logic:
    // Put Null Initially remove it from last. Change the arrow
    while (curr != NULL) {
        next = curr->next; //iter
        curr->next = prev; // logic
        prev = curr; //iter 
        curr = next; // iter
    }
    *head_ref = prev;
}

void push (struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//Remaining print and main func