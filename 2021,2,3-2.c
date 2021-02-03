#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}Node;

typedef struct {
    Node* head;
}stack_head;

stack_head* making_head(){
    stack_head* C= (stack_head*)malloc(sizeof(stack_head));
    C->head = NULL;
    return C;
}

void push(stack_head* C,int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->link =NULL;
    if(C->head ==NULL){
        C->head = new;
        return;
    }
    new->link = C->head;
    C->head = new;
}

void pop(stack_head* C){
    Node* temp =  C->head;
    if(temp==NULL){
        printf(" 스택이 비었습니다. ");
        return;
    }
    C->head = temp->link;
    int data = temp->data;
    free(temp);
    temp = NULL;
    printf("\n제거한 데이터: %d\n ",data);
    printf_stack(C);
}

void printf_stack(stack_head*C){
    Node* temp = C->head;
    printf("stack = [");
    while(temp !=NULL){
        printf(" %d ",temp->data);
        temp = temp->link;
    }
    printf("]");
    return;
}




int main(void){
    stack_head* C=making_head();
    push(C,22);
    push(C,14);
    push(C,51);
    push(C,62);
    push(C,44);
    printf_stack(C);
    pop(C);
}
