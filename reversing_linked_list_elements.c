#include<stdio.h>
#include<stdlib.h>
 
struct node	{
    int data;
    struct node* next;
};

void reverse(struct node** head_ref);
void push(struct node** head_ref, int new_data);
void printList(struct node *head);

int main()	{
  struct node* list = NULL;
  push(&list, 9);
  push(&list, 8);
  push(&list, 7);
  push(&list, 6);
  push(&list, 5);
  push(&list, 4);
  push(&list, 3);
  push(&list, 2);
  push(&list, 1); 
  push(&list, 0);      
  
  printf("\n Before \n");
  printList(list);    
  reverse(&list);                      
  printf("\n Reversed \n");
  printList(list);    
}

void reverse(struct node** head_ref)	{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL) {
        next = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
void push(struct node** head_ref, int new_data)	{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));     
    new_node->data = new_data;          
    new_node->next = (*head_ref);    
    (*head_ref) = new_node;
}
 
void printList(struct node *head)	{
    struct node *temp = head;
    while(temp != NULL)	{
        printf("%d_", temp->data);    
        temp = temp->next;  
    }
    printf("NULL\n");
}    
