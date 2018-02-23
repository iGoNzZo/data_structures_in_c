#include <stdio.h>
#include <stdlib.h>

struct character	{
	char c;
	struct character *next;
};

typedef struct character charNode;
typedef charNode *cNodePtr;

cNodePtr initializer(const char *string);
cNodePtr concat(cNodePtr a, cNodePtr b);
void printList(cNodePtr a);
void *memAllocate(size_t s);

void main()	{
	cNodePtr s1 = initializer("Hello ");
	cNodePtr s2 = initializer("World!");
	
	printList(s1);
	printList(s2);
	
	printList(concat(s1, s2));
}

cNodePtr initializer(const char *string)	{
	unsigned int i = 0;
	cNodePtr head = NULL;
	cNodePtr current = NULL;
	cNodePtr newNode = NULL;
	char buffer;
	
	while((buffer = *(string + i)) != '\0')	{
		newNode = memAllocate(sizeof(charNode));
		newNode->c = buffer;
		newNode->next = NULL;
		
		if(i > 0)	{
			current = current->next = newNode;
		} 
		else	{
			head = current = newNode;
		}
		i++;
	}
	return head; 
}

cNodePtr concat(cNodePtr a, cNodePtr b)	{
	cNodePtr current = a;
	
	while(current->next != NULL)	{
		current = current->next;
	}
	
	current->next = b;
	return (a);
}

void printList(cNodePtr a)	{
	cNodePtr current = a;
	while(current != NULL)	{
		printf("%c_", current->c);
		current = current->next;
	}
	printf("NULL\n");
}

void *memAllocate(size_t s)	{
	void *ptr;
	
	ptr = malloc(s);
	if(ptr == NULL)	{
		printf("Memory is full");
	}
	return ptr;
}
