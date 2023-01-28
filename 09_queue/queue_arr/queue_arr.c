#include<stdio.h>
#include<stdlib.h>
#include"queue_arr.h"

int* arr = NULL;
int size = 2;
int head = 0;
int tail = 0;

int deque(){
    if (head == tail)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    if (tail-head <= size/4)
    {
        int* arr2 = (int*)malloc(sizeof(int*)*size/2);
        for (int i = 0; i < tail-head; i++)
        {
            arr2[i] = arr[head+i];
        }
        tail -= head;
        head = 0;
        free(arr);
        size = size/2;
        arr = arr2;
    }
    
    return arr[head++];
    

}

void enque(int a){
    if (head == tail)
    {
        arr = (int*)malloc(sizeof(int*)*size);
    }
    if ( tail >= size)
    {
        size *= 2;
        int* arr2 = (int*)malloc(sizeof(int*)*size);
        for (int i = 0; i < size/2; i++)
        {
            arr2[i] = arr[i];
        }
        free(arr);
        arr = arr2;
    }
    arr[tail++] = a;
}


