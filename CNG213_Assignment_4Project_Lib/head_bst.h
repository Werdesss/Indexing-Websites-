#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

struct node 
{ 
	int ip;
	char name[50]; 
	struct node *left, *right; 
}; 

 
struct node *newNodeb(int ip,char name[]) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->ip = ip; 
	strcpy(temp->name,name);
	temp->left = temp->right = NULL; 
	return temp; 
} 


void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d %s \n", root->ip,root->name); 
		inorder(root->right); 
	} 
} 

struct node* insertb(struct node* node, int ip,char name[]) 
{ 
	if (node == NULL) return newNodeb(ip,name); 

	if (ip < node->ip) 
		node->left = insertb(node->left, ip,name); 
	else if (ip > node->ip) 
		node->right = insertb(node->right, ip,name); 

	return node; 
} 



