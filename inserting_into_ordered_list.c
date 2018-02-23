#include <stdio.h>
#include <stdlib.h>

struct listNode {
	int data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;


void insert(ListNodePtr *sPtr, int value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);

int main(void)	{
	ListNodePtr a = NULL;
	srand(time(NULL));
	int i;
	for (i = 0; i < 25; i++)	{
		int r = rand() % 100 + 1;
		insert(&a, r);
	}
	printList(a);
}

void insert(ListNodePtr *head, const int number)	{
	ListNodePtr new;

	for (; *head; head = &(*head)->nextPtr) {
		if ((*head)->data > number) break; // find the point to add it 
	}

	new = malloc(sizeof new);
	new->data = number;
	new->nextPtr = *head;
	*head = new;
}

int isEmpty(ListNodePtr sPtr)	{
	return sPtr == NULL;
}


void printList(ListNodePtr currentPtr)	{
	if (isEmpty(currentPtr)) {
		puts("List is empty.\n");
	}
	else {
		puts("The list is:");

		while (currentPtr != NULL) {
			printf(" %d , ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		puts("NULL\n");
	}
}
