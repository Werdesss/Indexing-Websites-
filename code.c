//Yusuf Mert Köseoðlu 2152072


#include<stdio.h>
#include<stdlib.h>
#include "head_avl.h"
#include "head_bst.h"

void insert_page(char name[],int ip,struct node *bst,struct Node *avl){
	insert(avl,ip,name);
	insertb(bst,ip,name);
}


void read_ip_data(struct node *bst,struct Node *avl){
	int ip,x;
	char name[50];
	
	FILE *file;
	file=fopen("URL.txt","r");	
	if (file==NULL){		
		printf("The file was not succesfully opened");
		exit(1);
	}
	else 
		printf("Your file has been loaded, the index has been created\n");
	
	fscanf(file,"%s > %d",&name,&ip);
	insert_page(name,ip,bst,avl);
	while ((x=fgetc(file))!=EOF){
		fscanf(file,"%s > %d",&name,&ip);
		insert_page(name,ip,bst,avl);
	}
}


void display_index(struct Node *avl){
	preOrder(avl);
}

void display_indexb(struct node *bst){
	inorder(bst);
}


void search_URL(struct Node *avl,char i){
	if(avl != NULL) { 
		if (i==avl->name)
			printf("IP addresses for %s:%d",avl->name,avl->ip); 
		search_URL(avl->left,i); 
		search_URL(avl->right,i); 
	} 
}

void search_URLb(struct Node *bst,char i){
	if(bst != NULL) { 
		search_URLb(bst->left,i); 
		if (i==bst->name)
			printf("IP addresses for %s:%d",bst->name,bst->ip);
		search_URLb(bst->right,i); 
	}  
}


void search_ip(struct Node *avl,int i){
	if(avl != NULL) { 
		if (i==avl->ip)
			printf("It belongs to %s",avl->name); 
		search_ip(avl->left,i); 
		search_ip(avl->right,i); 
	} 
}

void search_ipb(struct Node *bst,int i){
	if(bst != NULL) { 
		search_ipb(bst->left,i); 
		if (i==bst->ip)
			printf("It belongs to %s",bst->name);
		search_ipb(bst->right,i); 
	}  
}






int main(){
	int control=0,url;
	char page[50];
	struct node *bst=NULL;
	struct Node *avl=NULL;
	
	printf("Indexing Websites!\n");
	read_ip_data(bst,avl);	

	
	while (control!=8){
		printf("\n\n-------- MENU --------\n1. Display the full index in AVL tree\n2. Display the full index in BST tree\n3. Search for a URL From AVL tree\n4. Search for a URL From BST tree\n5. Search for an IP address From AVL tree\n6. Search for an IP address From BST tree\n7. Comparison of Run time\n8. Exit\n---------------------------\nOption:");
		scanf("%d",&control);
		switch (control){
			case 1:display_index(avl);break;
			case 2:display_indexb(bst);break;
			case 3:printf("\nPlease enter the page:");scanf("%s",&page);search_URL(avl,page);break;
			case 4:printf("\nPlease enter the page:");scanf("%s",&page);search_URLb(bst,page);break;
			case 5:printf("\nPlease enter the URL:");scanf("%d",&url);search_ip(avl,page);break;
			case 6:printf("\nPlease enter the URL:");scanf("%d",&url);search_ipb(bst,page);break;
			case 7:break;
			case 8:printf("\nGoodBye!");
		}
	}
	return 0;
}
