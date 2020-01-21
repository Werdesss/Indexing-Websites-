#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

struct Node 
{ 
	int ip;
	char name[50]; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 
 
int max(int a, int b); 

int height(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 


struct Node* newNode(int ip,char name[]) 
{ 
	struct Node* node = (struct Node*) 
						malloc(sizeof(struct Node)); 
	node->ip = ip;
	strcpy(node->name,name);
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1;
	return(node); 
} 

 
struct Node *rightRotate(struct Node *y) 
{ 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 
 
	return x; 
} 

struct Node *leftRotate(struct Node *x) 
{ 
	struct Node *y = x->right; 
	struct Node *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 
 
	return y; 
} 

int getBalance(struct Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 


struct Node* insert(struct Node* node, int ip,char name[]) 
{ 
	if (node == NULL) 
		return(newNode(ip,name)); 

	if (ip < node->ip) 
		node->left = insert(node->left, ip,name); 
	else if (ip > node->ip) 
		node->right = insert(node->right, ip,name); 
	else 
		return node; 

	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	int balance = getBalance(node); 


	if (balance > 1 && ip < node->left->ip) 
		return rightRotate(node); 
 
	if (balance < -1 && ip > node->right->ip) 
		return leftRotate(node); 

	if (balance > 1 && ip > node->left->ip) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 
 
	if (balance < -1 && ip < node->right->ip) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	return node; 
} 

 
void preOrder(struct Node *root) 
{ 
	if(root != NULL) 
	{ 
		printf("%d %s", root->ip,root->name); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

