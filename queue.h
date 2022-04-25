/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#ifndef QUEUE_H
#define QUEUE_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"

class Queue {

public:

    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    //constructor
    Queue(int);
    //destructor
    ~Queue();

    bool push(int, string*);
    bool peek(Data*);
    bool pop(Data*);
    bool isEmpty();
    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    Data **queue;
};

#endif //QUEUE_H
