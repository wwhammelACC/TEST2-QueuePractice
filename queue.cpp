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
    count = 0;
    back = -1;
    front = 0;
    if (userSize >= DEFAULT) {
        size = userSize;
    } else {
        size = DEFAULT;
    }
    queue = new Data *[size];
}


Queue::~Queue() {
    if(isEmpty() == false){
        delete queue[front];
        front = (front+1) % size;
        count--;
    }
}

// Utility function to add an item to the queue aka PUSH
bool Queue::enqueue(int id, std::string *str) {
    bool flag = false;
    if(!isFull() && (id > 0) && (!str->empty())){
        //allocate data structure
        back = (back + 1) % size;
        queue[back] = new Data;
        queue[back]->id = (id);
        queue[back]->information = *str;
        count++;
        flag = true;
    }
    return flag;
}

// Utility function to dequeue the front element aka POP
bool Queue::dequeue(Data *ref) {
    bool flag = false;
    if(!isEmpty()) {     // if not empty
        //getting info from top of stack and putting it in data struct
        ref->id = queue[front]->id;
        ref->information = queue[front]->information;
        delete queue[front];
        front = (front+1) % size; //have to change front here to step through it
        count--;
        flag = true;
    }else{
        //fill passed data struct with -1, empty string
        ref->id = -1;
        ref->information = "";
    }
    return flag;
}

// Utility function to return the front element of the queue aka PEEK
//PEEK METHOD/FUNCTION
bool Queue::peek(Data *ref) {
    bool peek = false;
    if(!isEmpty()){     // if not empty
        //getting info from top of stack and putting it in data struct
        ref->id = queue[front]->id;
        ref->information = queue[front]->information;
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
    return count == 0;
}

//full method
bool Queue::isFull(){
    return count == size;
}

//count
int Queue::getCount(){
    // count is internal and updated within insertEntry
    return count;
}

//from functions.h
#include "functions.h"

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;

    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete buffer;
    return;
}

// only digits taken from program fund 2 arrays project
bool is_positive_integer(char* onlyDigits)
{
    int i = 0;
    bool result = true;
    while((onlyDigits[i]) != '\0')
    {
        if(!isdigit(onlyDigits[i])) // if not digit false
        {
            result = false;
        }
        i++;
    }
    if(result == true)
    {
        if(atoi(onlyDigits) <= 0)
        {
            result = false;
        }
    }
    return result;
}