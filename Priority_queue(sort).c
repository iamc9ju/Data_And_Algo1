#include<stdio.h>
#define maxSize 100

int inDex = -1;

int pqVal[maxSize];
int pqPriority[maxSize];

int isEmpty(){
    return inDex == -1;
}

int isFull(){
    return inDex == maxSize -1;
}

void enqueue(int data, int priority){
    if(!isFull()){
        if(inDex == -1){
            inDex++;
            pqVal[inDex] = data;
            pqPriority[inDex] = priority;
            return;
        }else {
            inDex++;
            for (int i = inDex - 1; i >= 0; i--) {
                if (pqPriority[i] >= priority) {
                    pqVal[i + 1] = pqVal[i];
                    pqPriority[i + 1] = pqPriority[i];
                } else {
                    pqVal[i + 1] = data;
                    pqPriority[i + 1] = priority;
                    break;
                }
            }
        }
    }
}

int peek(){
    return  inDex;
}

void dequeue(){
    inDex--;
}

void display ()
{
    for (int i = 0; i <= inDex; i++)
    {
        printf ("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}

int main(){
    enqueue (25, 1);
    enqueue (10, 10);
    enqueue (15, 50);
    enqueue (20, 100);
    enqueue (30, 5);
    enqueue (40, 7);

    printf ("Before Dequeue : \n");
    display ();

    // // Dequeue the top element
    dequeue ();			// 20 dequeued

    printf ("\nAfter Dequeue : \n");
    display ();

    printf(" Peek value : %d",pqVal[peek()]);
    return 0;
}

