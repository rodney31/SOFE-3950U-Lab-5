#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <pthread.h>

/* these may be any values >= 0 */
#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 3

void resources(int customerNum); 
void acquire(lock *mutex);
void acquire(lock *mutex);
int requestResources(int customerNum, int request[]);
int releaseResources(int customerNum, int release[]);

typedef struct {
    bool available;
} lock;

int main(int argc, char **argv)
{ 
    srand(time(NULL)); 
    
    int available[NUMBER_OF_RESOURCES] = {argv[1] - '0', argv[2] - '0', argv[3] - '0', argv[4] - '0'}; /* the available amount of each resource */
    int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]; 
    int randomNumber;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            randomNumber = (rand() % 10) + 2;

            maximum[i][j] = randomNumber; 
        }
    }
    
    int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]; 
    int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]; 
    
    pthread_t tid[5];
    pthread_attr_t attr[5];

    for (int i = 0; i < 5 ;i++)
    {
        pthread_attr_init(&attr[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid[i], &attr[i], resources, i);
    }
}

public void resources(int customerNum) 
{
    mutex->available = true; 
    
    do{
        acquire(mutex);

        // Requesting and Releasing logic, including calls to functions, go between here 

        release(mutex);
        
    } while(true);
}

void acquire(lock *mutex)
{
    while (!mutex->available);
    
    mutex->available = false;
}

void release(lock *mutex)
{
    mutex->available = true; 
}
