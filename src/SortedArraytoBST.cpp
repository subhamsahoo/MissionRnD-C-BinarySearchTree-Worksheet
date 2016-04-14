/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

void insert(struct node **head, int n)
{
	if (*head == NULL)
	{
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = n;
		newnode->left = NULL;
		newnode->right = NULL;
		*head = newnode;
	}
	else
	{
		if (n>(*head)->data)
		{
			if ((*head)->right == NULL)
			{
				struct node *newnode = (struct node*)malloc(sizeof(struct node));
				newnode->data = n;
				newnode->left = NULL;
				newnode->right = NULL;
				(*head)->right = newnode;
			}
			else
			{
				insert(&((*head)->right), n);
			}
		}
		else if (n<(*head)->data)
		{
			if ((*head)->left == NULL)
			{
				struct node *newnode = (struct node*)malloc(sizeof(struct node));
				newnode->data = n;
				newnode->left = NULL;
				newnode->right = NULL;
				(*head)->left = newnode;
			}
			else{
				insert(&((*head)->left), n);
			}
		}
	}

}

void binarySearch(int arr[], int l, int r, struct node **head)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		insert(head, arr[mid]);
		binarySearch(arr, l, mid - 1, head);
		binarySearch(arr, mid + 1, r, head);
	}
}

struct node * convert_array_to_bst(int *arr, int len){
	if (arr==NULL||len<1)
	return NULL;
	struct node *head = NULL;
	binarySearch(arr,0,len-1,&head);
	return head;
}

