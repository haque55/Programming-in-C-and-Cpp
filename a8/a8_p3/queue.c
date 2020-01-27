/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
	// Check if queue is full
	if(queue_is_full(pq) == 1)
		return -1;
	else {
		// Create new node element
		Node *enqueueOn;
		enqueueOn = (Node *) malloc(sizeof(Node));
		if(enqueueOn == NULL) // Check if malloc was successful
			return -1;
		(*enqueueOn).item = item; // Assign value to new node
		(*enqueueOn).next = NULL;
		// Check if queue is empty
		if(queue_is_empty(pq) == 1) {
			// Front and rear element will be our new node
			(*pq).front = enqueueOn;
		} else {
			// Add link to the new node through the rear element
			(*(*pq).rear).next = enqueueOn;
		}
		// Set rear to new node
		(*pq).rear = enqueueOn;
		(*pq).items++;
		return 0;
	}
}

int dequeue(Item *pitem, Queue *pq)
{
	// Check if queue is empty
	if(queue_is_empty(pq) == 1)
		return -1;
	else {
		Node *temp;
		temp = (Node *) malloc(sizeof(Node));
		temp = (*pq).front;
		*pitem = (*(*pq).front).item; // Element dequeued assigned to pitem
		// Set front of queue to the next element in queue
		(*pq).front = (*(*pq).front).next;
		free(temp); // Free first element
		// Check if we only had 1 element in the queue
		if((*pq).items == 1) {
			// Set both front and rear of queue to NULL
			(*pq).front = NULL;
			(*pq).rear = NULL;
		}
		(*pq).items--; // Decrement item count by 1
		return 0;
	}
}


void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

void printq(Queue *pq) {
	// Create a cursor to go through the queue and initially set it at front
	Node *cursor = (*pq).front;
	printf("content of the queue: ");
	// Run until cursor hits a NULL element
	while(cursor != NULL) {
		// Print element cursor is currently pointing at and move to the next
		printf("%d ",(*cursor).item);
		cursor = (*cursor).next;
	}
	printf("\n");
}