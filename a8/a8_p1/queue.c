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
	// Decrement item count each time without implementing dequeue function
	// for a8_p1
	(*pq).items--;
	return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}