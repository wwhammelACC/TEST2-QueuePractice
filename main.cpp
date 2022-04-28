/*
 * your header here
 * 
 */

#include "main.h"

int main(int argc, char **argv) {
    if(argc == 2) {
        //borrowed from arrays prog fund2
        bool pos = is_positive_integer(argv[1]);
        int size = atoi(argv[1]);
        if (size >= 2 && pos == true) {
            // create stack
            int size = atoi(argv[1]);
            Queue queue(size);
            srand(time(NULL));

            std::cout << std::endl;
            std::cout << "Initial Testing of push, peek, pop and isEmpty" << std::endl;
            std::cout << std::endl;

            //INITIAL PUSH TESTING
            std::string strtemp;
            for (int i = 1; i < size; i++) {
                rand_string(&strtemp);
                if (strtemp.empty() || i < 0) {
                    std::cout << "Error. Int for id must be greater than 0 and string information cannot be empty."
                              << std::endl;
                } else if (queue.enqueue(i, &strtemp)) {
                    std::cout << "Queuing: ";
                    std::cout << "Integer ID: " << i << " Info: " << strtemp << std::endl;
                    std::cout << "Queued Element! " << std::endl;
                } else {
                    std::cout << "Overflow Error! " << std::endl;
                }
                std::cout << std::endl;
            }
            // testing isEmpty() on full stack
            if (queue.isEmpty()) {
                std::cout << "Queue is empty" << std::endl;
            } else {
                std::cout << "Queue is NOT empty" << std::endl;
            }
            std::cout << std::endl;

            //INITIAL PEEK TESTING
            Data *userData; // create variable pointer to empty Data struct
            userData = new Data; // userData is empty struct i think
            std::cout << std::endl;
            std::cout << "Testing peek function.." << std::endl;
            std::cout << "Peeking...." << std::endl;
            if(queue.peek(userData)){
                std::cout << "Integer ID: " << userData->id << " " << " Info: " << userData->information << std::endl;
            }else{
                std::cout << "Peek unsuccessful" << std::endl;
            }
            std::cout << std::endl;

            //INITIAL POP TESTING
            for(int i = 0; i<size; i++){
                //making pointer to an empty data struct to pass to pop and later to peek
                Data *userData; // create variable pointer to empty Data struct
                userData = new Data; // userData is empty struct i think
                std::cout << "Testing DeQueue function.. " << std::endl;
                if (queue.dequeue(userData)){
                    std::cout << "DeQueue successful! " << std::endl;
                }else {
                    std::cout << "Underflow error! " << std::endl;
                }
                std::cout << std::endl;
            }
            //************************************************
            //******** RANDOM TESTS ***************************
            //************************************************/

            std::cout << "Random testing..." << std::endl;
            std::cout << "============================================================" << std::endl;
            std::cout << std::endl;

            // clearing stack to start
            std::cout << "Clearing the stack to start!" << std::endl;
            while(!queue.isEmpty()){
                if (queue.dequeue(userData)){
                    std::cout << "DeQueue successful! " << std::endl;
                }else {
                    std::cout << "Underflow error! " << std::endl;
                }
                std::cout << std::endl;
            }

            // filling the stack half way to begin random tests
            for (int i = 0; i< int(size / 2); i++) {
                rand_string(&strtemp);
                if(strtemp.empty() || i<0){
                    std::cout << "Error. Int for id must be greater than 0 and string information cannot be empty." << std::endl;
                }
                else if (queue.enqueue(i, &strtemp)) {
                    std::cout << "Queueing: ";
                    std::cout << "Integer ID: " << i << " Info: " << strtemp << std::endl;
                    std::cout << "Queued Element! " << std::endl;
                }
                else {
                    std::cout << "Overflow Error! " << std::endl;
                }
                std::cout << std::endl;
            }

            // TESTING RANDOM OPERATIONS
            // push when CHOICES == 1 and 2, peek when == 3 and 4, pop when == 5, isEmpty when == 6;
            for (int i = 0; i < size*RANDOM_MULTIPLIER; i++) {
                int choice = rand() % CHOICES + 1;
                //PUSH
                if(choice == 1 || choice == 2){
                    rand_string(&strtemp);
                    if(strtemp.empty() || i<0){
                        std::cout << "Error. Int for id must be greater than 0 and string information cannot be empty." << std::endl;
                    }
                    else if (queue.enqueue(i, &strtemp)) {
                        std::cout << "Testing Queue function randomly...";
                        std::cout << "Integer ID: " << i << " Info: " << strtemp << std::endl;
                        std::cout << "Queued Element! " << std::endl;
                    }
                    else {
                        std::cout << "Overflow Error! " << std::endl;
                    }
                    std::cout << std::endl;
                    //POP
                }else if(choice == 3 || choice == 4){
                    std::cout << "Testing DeQueue function randomly..." << std::endl;
                    if (queue.dequeue(userData)){
                        std::cout << "DeQueue successful!" << std::endl;
                        std::cout << "DeQueued: " << "Integer ID: " << userData->id << " " << " Info: " << userData->information << std::endl;
                    }else {
                        std::cout << "Underflow error : DeQueue unsuccessful" << std::endl;
                    }
                    std::cout << std::endl;
                    //PEEK
                }else if(choice == 5){
                    std::cout << "Testing Peek function randomly..." << std::endl;
                    if(queue.peek(userData)){
                        std::cout << "Peeking...." << std::endl;
                        std::cout << "Integer ID: " << userData->id << " " << " Info: " << userData->information << std::endl;
                    }else{
                        std::cout << "Underflow error: Peek unsuccessful" << std::endl;
                    }
                    std::cout << std::endl;
                    //isEmpty
                }else if(choice == 6){
                    std::cout << "Testing isEmpty function randomly..." << std::endl;
                    if (queue.isEmpty()) {
                        std::cout << "stack is empty" << std::endl;
                    } else {
                        std::cout << "stack is NOT empty" << std::endl;
                    }
                    std::cout << std::endl;
                }
            }


        }
    }
    return 0;
}

