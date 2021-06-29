// Binary search tree - Implementation in C
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Tree
{
	struct Node* root;
	int nodecount;
};

void Insert(struct Tree*, int);
struct Node* GetNewNode(int);
void inorder_recursive(struct Node*);
Tree* createTree();
Node* insertNode(Node* root, int value);

int main()
{
	struct Tree* t1 = createTree();
	struct Tree* t2 = createTree();

	for (int i = 0; i < 2; i++)
	{
		Insert(t1, 15);
		Insert(t1, 10);
		Insert(t1, 20);
		Insert(t1, 25);
		Insert(t1, 8);
		Insert(t1, 12);
	}

	for (int i = 0; i < 3; i++)
	{
		Insert(t2, 100);
		Insert(t2, 200);
		Insert(t2, 300);
		Insert(t2, 400);
		Insert(t2, 500);
		Insert(t2, 600);
	}
	printf("\nNumber of Nodes in Tree1: \n");
	printf("%d", t1->nodecount);
	printf("\n Number of Nodes in Tree1:\n");
	printf("%d", t2->nodecount);

	printf("\nInorder Traversal Tree1: \n");
	inorder_recursive(t1->root);
	printf("\nInorder Traversal Tree2: \n");
	inorder_recursive(t2->root);

	_getch();
}

Tree* createTree()
{
	struct Tree* t = (struct Tree*)malloc(sizeof(struct Tree));
	t->root = NULL;
	t->nodecount = 0;
	return t;
}

struct Node* GetNewNode(int value)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	return newnode;
};

void Insert(struct Tree* t, int value)
{
	t->root = insertNode(t->root, value);
	t->nodecount++;
}

Node* insertNode(Node* root, int value)
{
	if (root == NULL)
	{
		root = GetNewNode(value);
	}
	else
	{
		if (root->data < value)
		{
			root->right = insertNode(root->right, value);
		}
		else
		{
			root->left = insertNode(root->left, value);
		}
	}

	return root;
}

void inorder_recursive(struct Node* root)
	{
		if (root == NULL)
			return;
		else
		{
			inorder_recursive(root->left);
			printf("%d ", root->data);
			inorder_recursive(root->right);
		}
	}