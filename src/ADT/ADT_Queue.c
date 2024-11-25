#include <stdio.h>
#include "../boolean.h"
#include "ADT_Queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isKosong(Queue q){
    return ((IDX_HEAD(q)==IDX_UNDEF) && (IDX_TAIL(q)==IDX_UNDEF));
}

boolean isPenuh(Queue q){
    return ((IDX_TAIL(q)-IDX_HEAD(q)+1)%KAPASITAS==0);
}

int length(Queue q){
    if (isKosong(q)){
        return 0;
    }
    else{
        if(IDX_HEAD(q)<=IDX_TAIL(q)){
            return (IDX_TAIL(q)-IDX_HEAD(q)+1);
        }
        else{
            return (KAPASITAS+IDX_TAIL(q)-IDX_HEAD(q)+1);
        }
    }
}

void enqueue(Queue *q, ElType val){
    if (isKosong(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else{
        IDX_TAIL(*q)+=1;
        IDX_TAIL(*q)=IDX_TAIL(*q)%KAPASITAS;
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
        IDX_HEAD(*q) = IDX_HEAD(*q)%KAPASITAS;
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
           for(int i = IDX_HEAD(q); i<KAPASITAS; i++){
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