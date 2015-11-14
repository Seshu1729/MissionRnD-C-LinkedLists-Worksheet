/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node 
{
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K)
{
	struct node *myNode;
	int i;
	if (K < 2||head==NULL)
		return NULL;
	myNode = head;
	do
	{
		for (i = 1; i < K - 1; i++)
		{
			myNode = myNode->next;
			if (myNode == NULL)
				return head;
		}
		if (myNode->next != NULL)
			myNode->next = myNode->next->next;
		myNode = myNode->next;
	} while (myNode != NULL);
	return head;
}