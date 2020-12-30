#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#define G 5 //정점갯수

typedef struct GNode{
    int data;
    struct GNode* link;
}GNode;



typedef struct Graph_Making{
    int n;
    GNode* array[MAX];
}Graph_Making;

//정점삽입
void Push_Graph(Graph_Making*C,int a){
    // 첫 정점은 0부터 시작
    if(a>n){
        printf("이미 그래프가 포화상태입니다.");
        return;
    }
    n++;

}


// graph 초기화
void Reset_Graph(Graph_Making*C){
    int i;
    for(i=0;i<n;i++){
        C->array[i] = NULL;
    }
}

// 간선 삽입하기
void Making_Graph(Graph_Making*C, int a, int b){
    if(a>n || b>n){
        printf("그래프에 존재하지 않는 노드데이터입니다.");
        return ;
    }
    GNode*new;
    new = (GNode*)malloc(sizeof(GNode));
    
    new->data = b;
    new->link = C->array[a];
    C->array[a] = new;
}

// 그래프 표현하기
void Printf_Grape(Graph_Making*C){
    int i =0;
    for(i=0;i<n;i++){
        GNode *temp;
        temp = C->array[i];
        printf(" &c =>", i+65);

        while(temp){
            printf(" &c ", temp->data);
            temp = temp->link;
        }
    }
}
distance[G][G] = {
    //  0   1  2  3  4
/*0*/   {0, 3, 5, 4, 0}, //0->1,2,3
/*1*/   {3, 0, 3, 0, 2}, // 1->0,2,4
/*2*/   {5, 3, 0, 4, 2}, // 
/*3*/   {4, 0, 4, 0, 4},
/*4*/   {0, 2, 2, 4, 0}
    }



// 최단거리 구하기 정점한개로 나머지 수까지 거리구하기
void Searching_distance(Graph_Making *C, int a){
    int i;

    for(i=0; i<C->n; i++){
        int ids = distancep[a][i];
        for(k=0; k<C->n; i++){
            if(dis > distance[a][k]+distance[k][i]){
                dis = distance[a][k] + distance[k][i];
            }
        } 
        
    }
}



int main(void){
    Graph_Making*C;
    Reset_Graph(C);

    Push_Graph(C,0);
    Push_Graph(C,1);
    Push_Graph(C,2);
    Push_Graph(C,3);
    Push_Graph(C,4);

    
    Making_Graph(C,0,3);
    Making_Graph(C,0,2);
    Making_Graph(C,0,1);
    Making_Graph(C,1,4);
    Making_Graph(C,1,2);
    Making_Graph(C,1,0);
    Making_Graph(C,2,4);
    Making_Graph(C,2,3);
    Making_Graph(C,2,0);
    Making_Graph(C,3,4);
    Making_Graph(C,3,2);
    Making_Graph(C,3,0);
    Making_Graph(C,4,3);
    Making_Graph(C,4,2);
    Making_Graph(C,4,1);

    Printf_Grape(C);
}
