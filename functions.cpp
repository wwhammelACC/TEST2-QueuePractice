/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

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
