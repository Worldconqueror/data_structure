#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct Node{
    int data;
    int vertax;
    struct Node* link;
}Node;

typedef struct{
    int member;
    Node* Node_list[MAX];
}graph;

typedef struct queue_Node{
    int data;
    struct queue_Node* link;
}queue_Node;


//너비 탐색을 위한 큐 생성
typedef struct {
    queue_Node* reaf;
    queue_Node* front;
}queue;

queue* making_queue(){
    queue* Q = (queue*)malloc(sizeof(queue));
    Q->reaf = NULL;
    Q->front =  NULL;
    return Q;
}


void making_queueNode(queue* Q,int data){
    queue_Node* target = (queue_Node*)malloc(sizeof(queue_Node));
    target->data =data;
    target->link =NULL;
    
    if(Q->front == NULL ){
        Q->front = target;
        Q->reaf = target;
        return ;
        
    }
    target->link = Q->reaf;
    Q->reaf = target;
    return ;
}

int delete_queue(queue* C){
    if(C->front==NULL){
        return 0;
    }
    if(C->front == C->reaf ){
        queue_Node* temp =C->front;
        int data = temp->data;
        free(temp);
        temp = NULL;
        C->front = NULL;
        C->reaf = NULL;
        return data;
    }
    queue_Node* temp = C->reaf;
    
    while(temp->link!=C->front){
        temp = temp->link;
    }
    queue_Node* target = C->front;
    int data = target->data;
    C->front = temp;
    free(target);
    return data;
}

// 너비 탐색 코드

void printf_width_searching(graph* C,int a){
    if(a>=MAX) {
        printf("너비 탐색 불가능\n");
        return ;
    
        
    }
    int acceess_list[MAX] ={0,0,0,0,0,0,0};
    Node* temp = C->Node_list[a];
    queue* Q = making_queue();
    printf("선택한 노드: %d \n",a);
    printf("이 노드를 기준으로 너비 탐색을 시작합니다.\n");
    acceess_list[a] =1;
    printf("[ %d",a);
    making_queueNode(Q,temp->vertax);
    while(temp){
        if(acceess_list[temp->vertax]==0){
            acceess_list[temp->vertax] =1;
            making_queueNode(Q,temp->vertax);
            printf(" %d ",temp->vertax);
        }
        else{
            temp= temp->link;
            if(temp==NULL){
                if(Q->front==NULL){
                    break;
                }
                int a = delete_queue(Q);
                temp = C->Node_list[a];
            }
        }
    }
    printf("]\n");
    printf("너비 탐색을 종료합니다.\n");
}







// 그래프 초기화
graph* making_graph(){
    graph* c = (graph*)malloc(sizeof(graph));
    c->member = 0;
    int i =0;
    for(i=0;i<MAX;i++){
        c->Node_list[i] = NULL;
    }
    return c;
}

//노드 생성
Node* making_Node(graph* C,int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->vertax = C->member;
    new->data = data;
    new->link = NULL;
    C->member++;
    printf("%d 의 노드 번호는 %d 입니다.\n",data,new->vertax);
    return new;
}

// 노드복사
Node* copy_node(Node* target){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = target->data;
    new->vertax= target->vertax;
    new->link = NULL;
    return new;
}

//노드끼리 연결
void link_Node(graph* C,Node* a,Node* b){
    Node* a_copy = copy_node(a);
    Node* b_copy = copy_node(b);
    a_copy->link = C->Node_list[b->vertax];
    C->Node_list[b->vertax] = a_copy;
    
    b_copy->link = C->Node_list[a->vertax];
    C->Node_list[a->vertax] = b_copy;
}

void printf_vertax_graph(graph* C){
    int i =0;
    for(i=0;i<MAX;i++){
        printf("%d번째 노드의 연결 노드:[",i);
        Node* temp = C->Node_list[i];
        while(temp!=NULL){
            printf(" %d ",temp->vertax);
            temp = temp->link;
        }
        printf("]\n");
    }
}

void printf_data_graph(graph* C){
    int i =0;
    for(i=0;i<MAX;i++){
        printf("%d번째 노드의 연결 노드:[",i);
        Node* temp = C->Node_list[i];
        while(temp!=NULL){
            printf(" %d ",temp->data);
            temp = temp->link;
        }
        printf("]\n");
    }
}

int main(){
    graph* C = making_graph();
    Node* a =making_Node(C,10);
    Node* b =making_Node(C,20);
    Node* c =making_Node(C,30);
    Node* d =making_Node(C,40);
    Node* e =making_Node(C,50);
    Node* f =making_Node(C,60);
    Node* g =making_Node(C,70);
    link_Node(C,a,b);
    link_Node(C,a,d);
    link_Node(C,a,e);
    link_Node(C,b,c);
    link_Node(C,c,d);
    link_Node(C,d,e);
    link_Node(C,e,f);
    link_Node(C,f,g);
    printf_data_graph(C);
    printf_vertax_graph(C);
    printf_width_searching(C,7);
    printf_width_searching(C,6);
    printf_width_searching(C,5);
    printf_width_searching(C,4);
    printf_width_searching(C,3);
    printf_width_searching(C,2);
    printf_width_searching(C,1);
    printf_width_searching(C,0);
}
