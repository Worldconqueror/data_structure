// linked list 를 사용한 queue 

#include <stdio.h>
#include <stdlib.h>


typedef struct queuedata{
    int data;
    struct queuedata *link;
}queuedata;

typedef struct inout{
    queuedata *front;
    queuedata *back;
} inout;

void CreateQueue(inout* A, int data){
    queuedata *new;
    new = (queuedata*)malloc(sizeof(queuedata));
    new->data =data;

    if(A->front = NULL){
        A->front = new;
        A->back = new;
    } 
    else {
        new->link = A->back;
        A->back = new; 
    }
}

int PopQueue(inout *A) {
    queuedata *temp;
    int value = 0;
    if(A->front = A->back){
        pritnf("큐에 데이터가 존재하지 않습니다.");
        return 0; 
    }
    else if (A->back->link = A->front){
        printf("마지막 노드가 삭제되었습니다.");
        return 1;
    }
    else {
        temp = A->back;
        while(temp->link !=temp->front){
            temp = temp->link;
        }
        A->front = temp;
        value = temp->link->data;
        free(temp->link);
        return value;
    }
}

int LenQueue(inout*A){
    int len =0;
    if(A->front = A->back){
        return len;
    }
    else {
        while(A->front->link != A->back){
            A->front = A->front->link;
            len++;
        }
    }
    return len+1;
}

void pritnf_queue(inout *A){
    queuedata *temp;
    temp = A->back;
    printf("[  ")
    while(temp != A->front){
        printf(" %d ",temp->data);
        temp = temp->link;    
    }
    printf(" %d  ]",temp->data);
    return ;
}