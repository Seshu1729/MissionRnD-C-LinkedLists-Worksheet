/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node 
{
	int data;
	struct node *next;
};

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sll_012_sort(struct node *head)
{
	struct node *pointer1, *pointer2;
	pointer1 = pointer2 = head;
	do
	{
		if (pointer2->data == 0)
		{
			swap(&pointer1->data, &pointer2->data);
			pointer1 = pointer1->next;
		}
		pointer2 = pointer2->next;
	}while (pointer2 != NULL);
	if (pointer1 != NULL)
	{
		pointer2 = pointer1;
		do
		{
			if (pointer2->data == 1)
			{
				swap(&pointer1->data, &pointer2->data);
				pointer1 = pointer1->next;
			}
			pointer2 = pointer2->next;
		} while (pointer2 != NULL);
	}
}