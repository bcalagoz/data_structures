#include<stdio.h>
#include<stdlib.h>
#include"queue_arr.h"

int main(){

    for (int i = 0; i < 20; i++)
    {
        enque(i*10);
    }
    printf("\n----->>>size=%d ---- head = %d ---- tail = %d ---\n",size,head,tail);
    for (int i = 0; i < 13; i++)
    {
        printf("%d  ",deque());
    }
    
    printf("\n----->>>size=%d ---- head = %d ---- tail = %d ---\n",size,head,tail);

    for (int i = 0; i < 20; i++)
    {
        enque(i*10);
    }

    printf("\n----->>>size=%d ---- head = %d ---- tail = %d ---\n",size,head,tail);

    for (int i = 0; i < 30; i++)
    {
        printf("%d  ",deque());
    }

    printf("\n----->>>size=%d ---- head = %d ---- tail = %d ---\n",size,head,tail);

}