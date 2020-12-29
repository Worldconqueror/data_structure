// 그래프 만들기 (무방향 연결 그래프 + 그래프 깊이 탐색(stack)이용)

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct GNode{
    int data;
    struct GNode * link;
}GNode;

typedef struct G_array {
    int n; //정점 갯수 나타냄;
    GNode* array[MAX];
    
}G_array;


//  G_array 초기화 하기
G_array* Reset_G(){
    int i;
    G_array* C;
    C =(G_array*)malloc(sizeof(G_array));
    C->n = 0;
    for(i=0;i<MAX; i++){
        C->array[i] = NULL;
    }
    return C;
}



// 정점갯수 더하기
void N_number(G_array* C,int a){
    if(a> C->n){
        printf("더이상 노드를 추가할수 없습니다.");
        return;
    }
    else {
        C->n++;
    }
}

// 정점에 간선 생성 (한 방향 간선 생성)
// 최소 데이터의 크기는 0부터 이다. 0부터 시작한 자연수들.
void Make_Edge(G_array* C,int a, int b){
    if(a>=C->n || b>= C->n){
        printf("존재하지 않는 노드(들) 입니다.");
        return;
    }
    else{
        GNode* new;
        new = (GNode*)malloc(sizeof(GNode));
        new->data = b;
        new->link = C->array[a];
        C->array[a] = new;
    }
}

// 그래프 노드들 나타내 보이기
void Printf_Grape(G_array* C){
    if(C->n == 0){
        printf("그래프가 비어있습니다.");
        return;
    }
    int i;
    
    GNode * temp;
    
    for(i=0; i< C->n; i++ ){
        temp = C->array[i];
        printf("%c번째 노드의 경로 :",i+65);
        while(temp->link !=NULL){
            printf(" %c -> ",temp->data+65);
            temp = temp->link;
        }
        if(temp ==NULL ){
                printf("데이터가 존재하지 않습니다.\n");
                continue;
            }
        else if(temp->link ==NULL){
            printf(" %c\n",temp->data +65);
        }
        
    }
    return ;
}
// 스택을 사용하여 깊이탐색 그래프 만들기

typedef struct Stack_node{
    int data;
    struct Stack_node* link;
}Stack_node;


Stack_node * top;


int pop(){
    if(top==NULL){
        printf("스택안이 비어있습니다.");
        return 1;
    }
    else{
        Stack_node *temp;
        temp = top;
        top = temp->link;
        int i =temp->data;
        free(temp);
        return i;
    }
}

void push(int data){
    if(top==NULL){
        Stack_node *new;
        new =(Stack_node*)malloc(sizeof(Stack_node));
        new->data =data;
        new->link =NULL;
        top = new;
        
    }
    else{
        Stack_node *new;
        new =(Stack_node*)malloc(sizeof(Stack_node));
        new->data = data;
        new->link =top;
        top = new;
        
    }
}

// 깊이 탐색하는 코드 (top, 전체그래프, 시작 정점)
void Deep_Searching(G_array*C,int a){
    int i,v;
    int array_number[C->n];
    for(i=0; i<C->n; i++){
        array_number[i] = 0;
    }

    array_number[a] = 1;
    printf("시작: %c  ",a +65);
    push(a);
    GNode *w;
    while(top!=NULL){
        v = pop();
        w = C->array[v];
        while(w!=NULL){
            
            if((array_number[w->data])!=1){
                array_number[w->data]= 1;
                printf(" %c  ",w->data+65);
                v = w->data;
                push(v);
            }
            else  {
                w= w->link;
            }
            
        }
    }
}






int main(void){
    G_array *C;
    C = Reset_G();
    
    N_number(C,0);
    N_number(C,1);
    N_number(C,2);
    N_number(C,3);
    N_number(C,4);
    N_number(C,5);
    Make_Edge(C,0,3);
    Make_Edge(C,0,2);
    Make_Edge(C,0,1);
    Make_Edge(C,1,3);
    Make_Edge(C,1,2);
    Make_Edge(C,1,0);
    Make_Edge(C,2,4);
    Make_Edge(C,2,3);
    Make_Edge(C,2,1);
    Make_Edge(C,2,0);
    Make_Edge(C,3,2);
    Make_Edge(C,3,1);
    Make_Edge(C,3,0);
    Make_Edge(C,3,4);
    Make_Edge(C,4,5);
    Make_Edge(C,4,3);
    Make_Edge(C,4,1);
    Make_Edge(C,5,4);
    Printf_Grape(C);
    Deep_Searching(C,0);
    printf("\n");
    Deep_Searching(C,1);
    printf("\n");
    Deep_Searching(C,2);
    printf("\n");
    Deep_Searching(C,3);
    printf("\n");
    Deep_Searching(C,4);
    printf("\n");
    Deep_Searching(C,5);
}
