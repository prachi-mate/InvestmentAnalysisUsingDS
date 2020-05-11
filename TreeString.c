#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	char key; 
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
		printf("%s", root->key); 
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
    //char "ShareA", "ShareB", "Home", "FD", "MutualFunds", "FarmingLand";
    char ShareA[]="ShareA";
    char ShareB[]="ShareB";
    char Home[]="Home";
    char FD[]="FD";
    char MutualFunds[]="MutualFunds";
    char FarmingLand[]="FarmingLand";
    
	/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	struct node *root; 
	root = insert(root, ShareA); 
	root = insert(root, Home); 
	root = insert(root, FD); 
	root = insert(root, MutualFunds); 
	root = insert(root, ShareB); 
	root = insert(root, FarmingLand); 

	printf("Inorder traversal of the given tree \n"); 
	inorder(root); 



	printf("\nDeleting Node With Maximum Profit : \n"); 
	root = deleteNode(root, Home); 
	printf("Inorder traversal of the modified tree \n"); 
	inorder(root); 

	return 0; 
} 

