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
ListNodePtr mergeStore(ListNodePtr *link1, ListNodePtr *link2);

int main(void)	{
	ListNodePtr a = NULL;
	ListNodePtr b = NULL;
	ListNodePtr c = NULL;
	int item;
	int i;
	for (i = 1; i < 10; i++)	{
		insert(&a, i);
		i++;
		insert(&b, i);
	}
	printList(a);
	printList(b);
	c = mergeStore(&a, &b);

	printList(c);
}

void insert(ListNodePtr *sPtr, int value)	{
	ListNodePtr newPtr = malloc(sizeof(ListNode));

	if (newPtr != NULL) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		ListNodePtr previousPtr = NULL;
		ListNodePtr currentPtr = *sPtr;

		while (currentPtr != NULL && value > currentPtr->data) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		printf("%c not inserted. No memory available.\n", value);
	}
}

ListNodePtr mergeStore(ListNodePtr *link1, ListNodePtr *link2)	{
	ListNodePtr a = *link1;
	ListNodePtr b = *link2;
	ListNodePtr c = NULL;
	ListNodePtr currentPtrA = (*link1)->nextPtr;
	ListNodePtr currentPtrB = (*link2)->nextPtr;
	if (isEmpty(a))
		c = b;
	else if (isEmpty(b))
		c = a;
	else	{
		while (a != NULL || b != NULL)	{
			if (a == NULL)	{
				insert(&c, b->data);
				b = b->nextPtr;
			}
			else if (b == NULL)	{
				insert(&c, a->data);
				a = a->nextPtr;
			}
			else	{
				if (b->data > a->data)	{
					insert(&c, a->data);
					a = a->nextPtr;
				}
				else	{
					insert(&c, b->data);
					b = b->nextPtr;
				}
			}
		}
	}
	return  c;
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
			printf(" %d ,", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		puts("NULL\n");
	}
}
