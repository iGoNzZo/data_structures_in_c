#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
	char data;
	struct StackNode *nextPtr;
};
typedef struct Stack stack;
typedef stack *stackptr;

void push(stackptr *topPtr, char word);
char popPrint(stackptr *top);
void printStack(stackptr currentPtr);


main()	{
	stackptr theStack = NULL;
	char str[250];
	char space[1] = " ";
	printf("Enter a Sentance: \n");
	fgets(str, 250, stdin);
	char *token;
	token = strtok(str, " \n"); //gets word
	while (token)	{
		size_t sizeW = strlen(token) - 1;
		int i;
		for (i = sizeW; i >= 0; i--)	{
			push(&theStack, token[i]);
		}
		push(&theStack, space[0]);
		token = strtok(NULL, " \n"); // getts next word
	}

	printStack(theStack);
	puts("");
	popPrint(&theStack);
	puts("");
}

void push(stackptr *topPtr, char word)	{
	stackptr newPtr;
	newPtr = malloc(sizeof(stack));

	if (newPtr != NULL)	{
		newPtr->data = word;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else	{
		puts("No memory");
	}
}

char popPrint(stackptr *top)	{
	stackptr temp = *top;;
	char value;
	printf("BackWords sentance:\n");
	while (temp != NULL)	{
		value = (*top)->data;

		printf("%c", value);

		*top = (*top)->nextPtr;
		free(temp);
		temp = *top;
	}
	puts("");
}

void printStack(stackptr currentPtr)	{
	// if stack is empty
	if (currentPtr == NULL) {
		puts("The stack is empty.\n");
	}
	else {
		puts("The stack is:");

		// while not the end of the stack
		while (currentPtr != NULL) {
			printf( "%c , ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		puts("NULL\n");
	}
}



