/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void totalNumberOfElements(struct node *root, int *count)
{
	if (root != NULL)
	{
		totalNumberOfElements(root->left, count);
		(*count)++;
		totalNumberOfElements(root->right, count);
	}

}

int height(struct node *root){

	int left = 0, right = 0;
	if (root == NULL)
		return 0;
	else
	{
		left = 1 + height(root->left);
		right = 1 + height(root->right);
		if (left>right)
			return left;
		else
			return right;
	}
}
void GivenLevel(struct node* root, int level, int *arr, int *size)
{
	if (root == NULL)
		return;
	if (level == 1)
		arr[(*size)++] = root->data;
	else if (level > 1)
	{
		GivenLevel(root->right, level - 1, arr, size);
		GivenLevel(root->left, level - 1, arr, size);
	}
}
void Order(struct node* root, int *arr)
{
	int size = 0;
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		GivenLevel(root, i, arr, &size);
}



int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int count = 0;
	totalNumberOfElements(root, &count);
	int *arr = (int*)malloc(sizeof(int)*count);
	Order(root, arr);
	return arr;

}
