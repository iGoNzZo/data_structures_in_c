#include <stdio.h>
#include <stdlib.h>

struct bin_tree	{
	int data;
	struct bin_tree * right, * left;
};

typedef struct bin_tree node;
 
node* search(node ** tree, int val)	{
	if(!(*tree))	{
		return NULL;
	}
	
	if(val < (*tree)->data)	{
		search(&((*tree)->left), val);
	}
	else if(val > (*tree)->data)	{
		search(&((*tree)->right), val);
	}
	else if(val == (*tree)->data)	{
		return *tree;
	}
}

//void deleteTree(node * tree);
//void printAfter(node * tree);
//void printInOrder(node * tree);
//void printBefore(node * tree);
//void insert(node ** tree, int val);

void deleteTree(node * tree)	{
	if(tree)	{
		deleteTree(tree->left);
		deleteTree(tree->right);
		free(tree);
	}
}

void printAfter(node * tree)	{
	if(tree)	{
		printAfter(tree->left);
		printAfter(tree->right);
		printf("%d\n", tree->data);
	}
}

void printInOrder(node * tree)	{
	if(tree)	{
		printInOrder(tree->left);
		printf("%d\n", tree->data);
		printInOrder(tree->right);
	}
}

void printBefore(node * tree)	{
	if(tree)	{
		printf("%d\n", tree->data);
		printBefore(tree->left);
		printBefore(tree->right);
	}
}

void insert(node ** tree, int val)	{
	node *temp = NULL;
	if(!(tree))	{
		temp = (node *)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}
	
	if(val < (*tree)->data)	{
		insert(&(*tree)->left, val);
	}
	else if(val > (*tree)->data)	{
		insert(&(*tree)->right, val);
	}
}

void main()	{
	node *root;
	node *temp;
	
	root = NULL;
	insert(&root, 18);
	insert(&root, 28);
	insert(&root, 83);
	insert(&root, 71);
	insert(&root, 40);
	insert(&root, 97);
	insert(&root, 44);
	insert(&root, 72);
	insert(&root, 32);
	insert(&root, 69);
	insert(&root, 11);
	insert(&root, 99);
	insert(&root, 92);
	insert(&root, 19);
	insert(&root, 49);
	
	//printf("before\n");
	//printBefore(root);
	
	//printf("sorted\n");
	//printInOrder(root);
	
	printf("After\n");
	printAfter(root);
	
		

}

