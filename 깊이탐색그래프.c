#include <stdio.h>
#include <stdlib.h>
#define MAX 7
typedef struct Node{
    int vertex; //data = vertex
    struct Node* link;
}Node;

typedef struct {
    int member;
    Node* Node_list[MAX];
    int stack_list[MAX];
}Node_Graph;



// 노드_그래프 생성
Node_Graph* making_ng(){
    Node_Graph* C = (Node_Graph*)malloc(sizeof(Node_Graph));
    C->member = 0;
    int i =0;
    for(i=0;i<MAX;i++){
        C->Node_list[i] =NULL;
    }
    
    for(i=0;i<MAX;i++){
        C->stack_list[i] =0;
    }
    return C;
}

// 노드 추가
void plus_vertex(Node_Graph* C){
    if(C->member>=MAX){
        printf("추가할수 없습니다.");
    }   
    C->member++;
}

//간선 연결
void plus_line(Node_Graph*C,int a, int b){
    if(a>C->member || b>C->member) return;
    
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->vertex = b;
    temp->link = C->Node_list[a];
    C->Node_list[a] = temp;
}
// 그래프 출력
void printf_graph(Node_Graph*C){
    if(C->member==0) return;
    
    int i =0;
    for(i=0;i<MAX;i++){
        printf(" %d번째 노드 :  ", i);
        Node* temp = C->Node_list[i];
        while(temp!=NULL){
            printf(" %d ",temp->vertex);
            temp = temp->link;
        }
        printf("\n");
    }
}
typedef struct stackNode{
    int data;
    struct stackNode* link;
}stackNode;

stackNode* top = NULL;

void push(int data){
    stackNode* new = (stackNode*)malloc(sizeof(stackNode));
    new->data = data;
    new->link= top;
    top= new;
}

int pop(){
    if(top ==NULL) return -1;
    stackNode* temp = top;
    top = top->link;
    int a = temp->data;
    free(temp);
    temp =NULL;
    return a;
}
void deep_searching(Node_Graph*C,int a){
    printf("깊이 탐색: %d ",a);
    Node* temp = C->Node_list[a];
    push(a);
    C->stack_list[a] = 1;
    a = temp->vertex;
    
    while(temp){
        if(C->stack_list[a]==0){
            printf(" %d ",temp->vertex);
            C->stack_list[a] = 1;
            push(temp->vertex);
            temp = C->Node_list[temp->vertex];
            a = temp->vertex;
        }
        
        else{
            temp = temp->link;
            if(temp!=NULL){
                a=temp->vertex;
            }
            else if(temp ==NULL){
                int a = pop();
                if(a==-1) break;
                temp = C->Node_list[a];
            }
        }
    }

}




int main(void){
    int i =0;
    Node_Graph* C = making_ng();
    for(i=0;i<MAX;i++){
        plus_vertex(C);
    }
    
    plus_line(C,0,1);
    plus_line(C,0,2);
    plus_line(C,1,0);
    plus_line(C,1,3);
    plus_line(C,1,4);
    plus_line(C,2,0);
    plus_line(C,2,4);
    plus_line(C,3,1);
    plus_line(C,3,5);
    plus_line(C,4,1);
    plus_line(C,4,2);
    plus_line(C,4,5);
    plus_line(C,5,3);
    plus_line(C,5,4);
    plus_line(C,5,6);
    plus_line(C,6,5);
    printf_graph(C);
    deep_searching(C,0);
}




