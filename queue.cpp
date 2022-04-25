/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

// each cpp includes ONLY it's header directly
#include "queue.h"

/*
 * write all your stack methods here
 */

//Enqueue: Inserts a new element at the rear of the queue.
//Dequeue: Removes the front element of the queue and returns it.
//Peek: Returns the front element present in the queue without dequeuing it.
//IsEmpty: Checks if the queue is empty.
//IsFull: Checks if the queue is full.
//Size: Returns the total number of elements present in the queue.

Queue::Queue(int userSize) {

    top = -1;
    if (userSize >= DEFAULT) {
        size = userSize;
    } else {
        size = DEFAULT;
    }
    queue = new Data *[size];
}


Queue::~Queue() {
    for(int i=top; i>=0; i--){
        delete queue[i];
    }
    delete[] queue; // goes in destructor
}

// Utility function to add an item to the queue aka PUSH

// Utility function to dequeue the front element aka POP

// Utility function to return the front element of the queue aka PEEK

// Utility function to return the size of the queue

// Utility function to check if the queue is empty or not