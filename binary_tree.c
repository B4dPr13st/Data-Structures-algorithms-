#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct binary_tree
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
}myTree;

int is_empty(myTree *tree)
{
	if (tree == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Printing in post order
void post_order(myTree *tree)
{
	if (!is_empty(tree))
	{
		post_order(tree->left);
		post_order(tree->right);
		printf("%d\n", tree->item);
	}
}

//Printing in pre order
void pre_order(myTree *tree)
{
	printf("%d\n", tree->item);
	pre_order(tree->left);
	pre_order(tree->right);
}

//Printing in order
void in_order(myTree *tree)
{
	in_order(tree->left);
	printf("%d\n", tree->item);
	in_order(tree->right);
}

//Searching in tree
myTree* search(myTree *tree, int item)
{
	//The tree is empty!
	if ((tree == NULL) || (tree->item == item))
	{
		return tree;
	}
	//Go to the left, the lower itens stay o left side of the edges!
	else if (tree->item > item)
	{
		return search(tree->left, item);
	}
	//Counter-case
	else
	{
		return search(tree->right, item);
	}
}

//Function to insert the new edge with the instructions of the add function
myTree* create_tree(int item, myTree *left, myTree *right)
{
	myTree *new_tree = (myTree*)malloc(sizeof(myTree));
	new_tree->item = item;
	new_tree->left = left;
	new_tree->right = right;
	return new_tree;
}

//Function to select where the new edge will be insert, to make the tree a binary tree
myTree* add(myTree *tree, int item)
{
	//If tree is NULL, that is a leaf, so add the new edge here
	if (tree == NULL)
	{
		tree = create_tree(item, NULL, NULL);
	}
	//If item is lower than item on the struct, the new function recalls in the left side
	//Lower itens are ever insert on the left side of the actual edge
	else if (tree->item > item)
	{
		tree->left = add(tree->left, item);
	}
	//Counter-case of the last elseif
	else
	{
		tree->right = add(tree->right, item);
	}
	return tree;
}

//Function to starts the tree in empty state
myTree* starts_tree()
{
	return NULL;
}

int main()
{
	myTree *root = starts_tree();
	return 0;
}