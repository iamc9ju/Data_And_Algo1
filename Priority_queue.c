#include <stdio.h>
#include <limits.h>

#define maxSize 100

int inDex = -1;


int pqVal[maxSize]; //hold data
int pqPriority[maxSize]; //hold priority queue

int isEmpty(){
    return inDex == -1;
}

int isFull(){
    return inDex == maxSize -1;
}

void enqueue(int data,int priority){
    if(!isFull()){
        inDex++;

        pqVal[inDex] = data;
        pqPriority[inDex] = priority;
    }
}

//return item with higher priority
int peek(){
    int max_priority = INT_MIN;
    int indexPos = -1;

    //linear search for highest priority
    for(int i=0;i<=inDex;i++){
        //if two items have same priority choose one with higher value
        if(max_priority == pqPriority[i] && indexPos > -1 &&
        pqVal[indexPos] < pqVal[i]){
            max_priority = pqPriority[i];
            indexPos = i;
        }else{
            if (max_priority < pqPriority[i]){
                max_priority = pqPriority[i];
                indexPos = i;
            }
        }
    }
    return indexPos;
}

//This remove the element with highest priority

void dequeue(){
    if(!isEmpty()){
        int indexPos = peek();

        for(int i = indexPos;i<inDex;i++){
            pqVal[i] = pqVal[i+1];
            pqPriority[i] = pqPriority[i+1];
        }
    }
    inDex--;
}
void display ()
{
    for (int i = 0; i <= inDex; i++)
    {

        printf ("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}

int main ()
{
    // To enqueue items as per priority
    enqueue(5,1);
    enqueue(10,3);
    enqueue(15,4);
    enqueue(20,5);
    enqueue(500,2);

    printf ("Before Dequeue : \n");
    display ();

    dequeue();
    printf ("After Dequeue : \n");
    display ();

    dequeue();
    printf ("After Dequeue : \n");
    display ();

    dequeue();
    printf ("After Dequeue : \n");
    display ();

    dequeue();
    printf ("After Dequeue : \n");
    display ();

    return 0;

}




