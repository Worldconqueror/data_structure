#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* link;
    
}Node;

typedef struct{
    Node* front;
    Node* reaf;
}queue;

queue* making_queue(){
    queue* C = (queue*)malloc(sizeof(queue));
    C->front =NULL;
    C->reaf = NULL;
    return C;
}

void add_data(queue* C,int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->link = NULL;
    if(C->front ==NULL){
        C->front =new;
        C->reaf = new;
        return;
    }
    new->link = C->reaf;
    C->reaf = new;
    return;
}

Node* searching_queue(queue* C, int data){
    if(C->front==NULL){
        printf("큐가 비었습니다 \n");
        return C->front;
    }
    Node* temp = C->reaf;
    while(temp->data!=data){
        temp =temp->link;
    }
    if(temp==NULL){
        printf("큐에 존재하지않는 데이터입니다.\n");
        return temp;
    }
    return temp;
    
}

void printf_queue(queue* C){
    Node* temp =C->reaf;
    if(temp==NULL){
        printf("큐가 비었습니다.\n");
        return;
    }
    printf("queue=[");
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp = temp->link;
        if(temp==NULL){
            printf("]");
            return;
        }
    }
}

void delete_queue(queue* C){
    Node* temp = C->front;
    Node* temp2 = C->reaf;
    int data =temp->data;
    
    while(temp2->link!=temp){
        temp2 = temp2->link;
    }
    free(temp);
    temp = NULL;
    C->front = temp2;
    temp2->link =NULL;
    printf("삭제한 데이터: %d\n",data);
    printf_queue(C);
    return;
}

int main(void){
    queue* C =making_queue();
    add_data(C,24);
    add_data(C,51);
    add_data(C,21);
    add_data(C,94);
    add_data(C,45);
    printf_queue(C);
    Node* temp =searching_queue(C,94);
    delete_queue(C);
}
