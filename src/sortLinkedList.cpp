/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include<stdlib.h>

struct node 
{
	int num;
	struct node *next;
};

int getLength(struct node *head)
{
	int length = 0;
	while (head != NULL)
	{
		head = head->next;
		length++;
	}
	return length;
}

struct node * sortLinkedList(struct node *head)
{
	struct node *tempHead = head,*nodei,*nodej;
	int length,i,j,temp;
	if (head == NULL)
		return NULL;
	length = getLength(tempHead);
	for (nodei = head, i = 0; i < length; i++)
	{
		for (nodej = head, j = 0; j < length - i - 1; j++)
		{
			if (nodej->num > nodej->next->num)
			{
				temp = nodej->next->num;
				nodej->next->num = nodej->num;
				nodej->num = temp;
			}
			nodej = nodej->next;
		}
		nodei = nodei->next;
	}
	return head;
}

/*
METHOD 2:
Actually it violates basic condions of given problem

void heapUp(int *heap, int index)
{
	int value = heap[index];
	while (index>1 && heap[index / 2]<value)
	{
		heap[index] = heap[index / 2];
		index /= 2;
	}
	heap[index] = value;
}

void heapDown(int *heap, int index, int length)
{
	int value = heap[index], child = index * 2;
	while (child <= length)
	{
		if (child<length&&heap[child]<heap[child + 1])
			child++;
		if (heap[child]<heap[child / 2])
			break;
		heap[child / 2] = heap[child];
		child *= 2;
	}
	heap[child / 2] = value;
}

struct node * sortLinkedList(struct node *head) 
{
	struct node *tempHead = head;
	int length, index = 1, tempLength, tempvar, *heap;
	if (head == NULL)
		return NULL;
	length = getLength(tempHead);
	heap = (int *)malloc(sizeof(int)*(length + 1));
	tempHead = head;
	do
	{
		heap[index] = tempHead->num;
		heapUp(heap, index);
		tempHead = tempHead->next;
		index++;
	} while (tempHead != NULL);
	tempLength = length;
	for (index = 1; index <= length; index++)
	{
		tempvar = heap[1];
		heap[1] = heap[tempLength];
		heap[tempLength] = tempvar;
		tempLength--;
		heapDown(heap, 1, tempLength);
	}
	tempHead = head;
	for (index = 1; index <= length; index++)
	{
		tempHead->num = heap[index];
		tempHead = tempHead->next;
	}
	return head;
}

*/