#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 


struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 


void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d ", root->key); 
		inorder(root->right); 
	} 
} 


struct node* insert(struct node* node, int key) 
{ 
	if (node == NULL) return newNode(key); 


	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 


	return node; 
} 


struct node * minValueNode(struct node* node) 
{ 
	struct node* current = node; 


	while (current->left != NULL) 
		current = current->left; 

	return current; 
} 


struct node* deleteNode(struct node* root, int key) 
{ 

	if (root == NULL) return root; 


	if (key < root->key) 
		root->left = deleteNode(root->left, key); 


	else if (key > root->key) 
		root->right = deleteNode(root->right, key); 


	else
	{ 

		if (root->left == NULL) 
		{ 
			struct node *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct node *temp = root->left; 
			free(root); 
			return temp; 
		} 


		struct node* temp = minValueNode(root->right); 


		root->key = temp->key; 


		root->right = deleteNode(root->right, temp->key); 
	} 
	return root; 
} 


int main() 
{ 
	/*
		 10000 
	   	/	 \ 
  1000000   500000 
	 /                 / \ 
  50000 15000  300000
   */
  
	struct node *root = NULL; 
	root = insert(root, 1000000); 
	root = insert(root, 10000); 
	root = insert(root, 50000); 
	root = insert(root, 500000); 
	root = insert(root, 15000); 
	root = insert(root, 300000); 

	printf("Inorder Traversal Of The Given Tree:  \n"); 
	inorder(root); 

	printf("\n \n Deleting Node With Maximum Profit"); 
	root = deleteNode(root, 1000000); 
	printf("\n \nModified Tree :\n"); 
	inorder(root); 


	return 0; 
} 

