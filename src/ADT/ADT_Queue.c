#include <stdio.h>
#include "boolean.h"
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return ((IDX_HEAD(q)==IDX_UNDEF) && (IDX_TAIL(q)==IDX_UNDEF));
}

boolean isFull(Queue q){
    return ((IDX_TAIL(q)-IDX_HEAD(q)+1)%CAPACITY==0);
}

int length(Queue q){
    if (isEmpty(q)){
        return 0;
    }
    else{
        if(IDX_HEAD(q)<=IDX_TAIL(q)){
            return (IDX_TAIL(q)-IDX_HEAD(q)+1);
        }
        else{
            return (CAPACITY+IDX_TAIL(q)-IDX_HEAD(q)+1);
        }
    }
}

void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else{
        IDX_TAIL(*q)+=1;
        IDX_TAIL(*q)=IDX_TAIL(*q)%CAPACITY;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if(length(*q)==1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q)+=1;
        IDX_HEAD(*q) = IDX_HEAD(*q)%CAPACITY;
    }
}

void displayQueue(Queue q){
    printf("[");
    if(length(q)!=0){
        if(IDX_HEAD(q)<=IDX_TAIL(q)){
            for(int i = IDX_HEAD(q); i<=IDX_TAIL(q); i++){
                if(i!=IDX_TAIL(q)){
                    printf("%d,",q.buffer[i]);
                }
                else{
                    printf("%d",q.buffer[i]);
                }
            }
        }
        else{
           for(int i = IDX_HEAD(q); i<CAPACITY; i++){
                printf("%d,",q.buffer[i]);
           }
           for(int i = 0; i<=IDX_TAIL(q); i++){
                if(i!=IDX_TAIL(q)){
                    printf("%d,",q.buffer[i]);
                }
                else{
                    printf("%d",q.buffer[i]);
                }
            }
        }
    }
    printf("]\n");
}