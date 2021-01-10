// 순차 자료구조로 스택표현

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}Node;

Node* top;

void Push_top(int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = top;
    top = temp;
}

int Delete_top(){
    if(top==NULL){
        printf("스택이 비어있습니다.");
        return 0;
    }



    int data = top->data;
    Node* temp = top;
    top = temp->link;
    free(temp);
    temp = NULL;
    
    return data;

}

int Searching_TOP(){
    if(top==NULL){
        printf("스택이 비어있습니다.");
        return 0;
    } 
    int data;
    data = top->data;
    return data;
}

void Printf_Stack(){
    if(top==NULL){
        printf("스택이 비어있습니다.");
        return ;
    }
    
    Node* temp = top;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp = temp->link;
    }
    return ;
}






int main(void){
    top = NULL;
    Push_top(1);
    Push_top(2);
    Push_top(3);
    Push_top(4);
    Push_top(5);
    Push_top(6);
    Push_top(7);
    Printf_Stack();
    printf("\n %d \n",Delete_top());
    Printf_Stack();
    printf("\n%d\n",Searching_TOP());
    Printf_Stack();
    



    exit(0);
};
