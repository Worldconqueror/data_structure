#include <stdio.h>
#include <stdlib.h>
#define MAX 6
typedef struct Node{
    int vertex; //data = vertex
    struct Node* link;
}Node;

typedef struct {
    int member;
    Node* Node_list[MAX];
}Node_Graph;


// 노드_그래프 생성
Node_Graph* making_ng(){
    Node_Graph* C = (Node_Graph*)malloc(sizeof(Node_Graph));
    C->member = 0;
    int i =0;
    for(i=0;i<MAX;i++){
        C->Node_list[i] =NULL;
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


int main(void){
    Node_Graph* C = making_ng();
    int i =0;
    for(i=0;i<MAX;i++){
        plus_vertex(C);
    }
    plus_line(C,0,1);
    plus_line(C,0,5);
    plus_line(C,1,0);
    plus_line(C,1,2);
    plus_line(C,2,1);
    plus_line(C,2,3);
    plus_line(C,3,2);
    plus_line(C,4,5);
    plus_line(C,5,1);
    plus_line(C,5,4);
    printf_graph(C);
}
