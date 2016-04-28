/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int distBelow(struct node *root)
{
	int l = -1, r = -1;
	if (root->left == NULL&&root->right == NULL)
		return 0;
	if (root->left != NULL)
		l = distBelow(root->left);
	if (root->right != NULL)
		r = distBelow(root->right);
	if (l == -1)
	{
		if (r != -1)
			return  r + 1;
		else return -1;
	}
	else if (r == -1)return l + 1;
	else return l<r ? l + 1 : r + 1;
}

void find(struct node *root, int key, int *res, int *i, int *j)
{
	(*i)++;
	struct node *prev;
	int temp;
	if (root == NULL)
		return;
	if (key == root->data)
	{
		*res = distBelow(root);
		(*j) = (*i) - 1;
	}
	else if (key < root->data)
	{
		prev = root;
		find(root->left, key, res, i, j);
		if (*res != -1)
		{
			temp = distBelow(prev) + (*i) - (*j);
			(*j)--;
			if (*res>temp)*res = temp;
		}
	}
	else
	{

		prev = root;
		find(root->right, key, res, i, j);
		if (*res != -1)
		{
			temp = distBelow(prev) + (*i) - (*j);
			(*j)--;
			if (*res > temp)*res = temp;
		}
	}
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	int res = -1, i = 0, j = 0;
	if (root == NULL || temp == NULL)return -1;
	else
	{
		find(root, temp->data, &res, &i, &j);
		return res;
	}
}
