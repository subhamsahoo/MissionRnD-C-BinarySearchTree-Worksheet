/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>

int value1 = 0, value2 = 0;
struct node{
	struct node * left;
	int data;
	struct node *right;
};
void totalNumberOfElements2(struct node *root, int *count)
{
	if (root != NULL)
	{
		totalNumberOfElements2(root->left, count);
		(*count)++;
		totalNumberOfElements2(root->right, count);
	}

}
void inorder2(struct node *root, int *arr, int *size)
{
	if (root != NULL)
	{
		inorder2(root->left, arr, size);
		arr[(*size)++] = root->data;
		inorder2(root->right, arr, size);
	}

}
void find(int *a, int count)
{
	int i, j;
	for (i = 0; i<count; i++)
	{
		if (a[i]>a[i + 1])
		{
			value1 = a[i];
			break;
		}
	}
	for (j = i + 1; j<count; j++)
	{
		if (a[j]>a[j + 1])
		{
			value2 = a[j + 1];
			break;
		}
	}
	if (value2 == 0)
	{
		value2 = a[i + 1];
	}
}
void fixingtree(struct node *root)
{
	if (root != NULL)
	{
		fixingtree(root->left);
		if (root->data == value1)
			root->data = value2;
		else if (root->data == value2)
			root->data = value1;
		fixingtree(root->right);
	}
}


void fix_bst(struct node *root){
	if (root==NULL)
	{ }
	else{
		int count = 0, size = 0;
		totalNumberOfElements2(root, &count);
		int *arr = (int*)malloc(sizeof(int)*count);
		inorder2(root, arr, &size);
		value1 = 0;
		value2 = 0;
		find(arr, count);
		fixingtree(root);
	}
}
