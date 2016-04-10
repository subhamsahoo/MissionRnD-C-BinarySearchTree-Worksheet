/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int in = 0, pre = 0, post = 0;
void inorderHelper(struct node *root, int *arr){
	if (root != NULL)
	{
		inorderHelper(root->left, arr);
		arr[in++] = root->data;
		inorderHelper(root->right, arr);
	}

}
void inorder(struct node *root, int *arr)
{
	if (arr == NULL)
		return;

	in = 0;
	inorderHelper(root, arr);
}
void preorderHelper(struct node *root, int *arr){
	if (root != NULL)
	{
		arr[pre++] = root->data;
		preorderHelper(root->left, arr);
		preorderHelper(root->right, arr);
	}
}
void preorder(struct node *root, int *arr)
{
	if (arr == NULL)
		return;
	pre = 0;
	preorderHelper(root, arr);
}
void postorderHelper(struct node *root, int *arr){
	if (root != NULL)
	{
		postorderHelper(root->left, arr);
		postorderHelper(root->right, arr);
		arr[post++] = root->data;
	}
}
void postorder(struct node *root, int *arr)
{
	if (arr == NULL)
		return;
	post = 0;
	postorderHelper(root, arr);
}

