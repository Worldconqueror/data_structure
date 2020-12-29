// 그래프 만들기 (무방향 연결 그래프 + 너비 탐색 그래프(큐이용))

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
// 큐를 사용하여 너비탐색 방법
// 큐노드 정의
typedef struct QNode{
    int data;
    struct QNode *link;
} QNode;

// 큐의 앞부분, 뒷부분 표시.
typedef struct front_reaf{
    QNode * reaf;
    QNode *front;
}front_reaf;

// front_reaf 정의
front_reaf* Make_front_reaf(){
    front_reaf* new;
    new = (front_reaf*)malloc(sizeof(Make_front_reaf));
    new->reaf = NULL;
    new->front = NULL;

    return new;
}

//reaf에 삽입
void push(front_reaf*C,int data){
    QNode *new;
    new = (QNode*)malloc(sizeof(QNode));
    
    if(C->front ==NULL){
        new->data = data;
        new->link = NULL;    
        C->front = new;
        C->reaf = new;
    }
    else {
        new->data = data;
        QNode *temp;
        temp = C->front;
        while(temp->link !=NULL){
            temp = temp->link;
        }
        temp->link = new;
        new->link = NULL;
        C->reaf = new;
    }
}

// front 빼기
int pop(front_reaf*C){
    QNode *temp;
    temp= C->front;
    if(C->front == C->reaf){
        int i = temp->data;
        free(temp);
        return i;
    }
    C->front = temp->link;
    int data = temp->data;
    free(temp);
    temp =NULL;
    return data;
}

// 너비 탐색 그래프 
void Wide_Searching(front_reaf*A, G_array*B,int c){
    int array_true[B->n];
    int i;
    
    // array_true 초기화 시키기//
    for(i=0; i<B->n;i++){
        array_true[i]=0;
    }
    array_true[c] = 1;
    
    push(A,c);
    printf("시작점: %c =>> ",c+65 );
    for(i=0;i<B->n;i++){
        int alpha;
        alpha = pop(A);
        GNode *temp = B->array[alpha];
        while(temp!=NULL){
            if(array_true[temp->data]==0){
                alpha = temp->data;
                array_true[alpha]=1;
                push(A,alpha);
                printf(" %c ",temp->data+65);
            }
            else{temp = temp->link;
            
                }
            
        }

    }
}





int main(void){
    G_array *C;
    C = Reset_G();
    front_reaf*A;
    A= Make_front_reaf();

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
    Wide_Searching(A,C,0);
    printf("\n");
    Wide_Searching(A,C,1);
    printf("\n");
    Wide_Searching(A,C,2);
    printf("\n");
    Wide_Searching(A,C,3);
    printf("\n");
    Wide_Searching(A,C,4);
    printf("\n");
    Wide_Searching(A,C,5);
}
