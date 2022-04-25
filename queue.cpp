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
bool Queue::enqueue(int id, std::string *str) {
    bool flag = false;
    std::cout << "Testing initial enqueue " << std::endl;
    if (top < size - 1) {
        if(id > 0 && !str->empty()){
            // pointer to data struct
            Data *myData;
            //allocate data structure
            myData = new Data;
            myData->id = (id);
            myData->information = *str;
            top = (top + 1) % size;
            queue[++top] = myData;
            flag = true;
        }
    }
    return flag;
}

// Utility function to dequeue the front element aka POP
bool Queue::dequeue(Data *ref) {
    bool flag = false;
    std::cout << "Testing initial dequeue " << std::endl;
    return flag;
}

// Utility function to return the front element of the queue aka PEEK
//PEEK METHOD/FUNCTION
bool Queue::peek(Data *ref) {
    bool peek = false;
    if(!isEmpty()){     // if not empty
        //getting info from top of stack and putting it in data struct
        ref->id = queue[top]->id;
        ref->information = queue[top]->information;
        //'return data to caller'
        peek = true;
    }else{
        //fill passed data struct with -1, empty string
        ref->id = -1;
        ref->information = "";
    }
    return peek;
}
// Utility function to check if the queue is empty or not
//ISEMPTY METHOD/FUNCTION
bool Queue::isEmpty(){
    return top < 0;
}

// Utility function to return the size of the queue
