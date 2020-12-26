//complete graph DataStructure
#include <stdio.h>
#include <stdlib.h>
#define max 100
int i = 0;

typedef struct grapeVer{
    int data;
    struct grapeVer*link;
}grapeVer;

typedef struct grape_main{
    grapeVer* array[max];
}grape_main;

// 공백 그래프 생성
grape_main* Make_graph(){
    int k =0;
    grape_main*C;
    C = (grape_main*)malloc(sizeof(grape_main));
    for(k=0;k<max;k++){
        C->array[k] = NULL;
    }
    return C;
}

// 그래프에 정점 집어넣기

int Make_ver(grape_main* C, int data){
    grapeVer * new;
    new =(grapeVer*)malloc(sizeof(grapeVer));
    new->data = data;
    C->array[i] = new;
    new->link = NULL;
    i++;
    return i-1; // 이값이 그래프의 정점의 위치;
}


// 두 정점사이에 간선 연결하기

void Make_Edge(grape_main *C, int a, int b,int data, int data2){
    if(a>i || b>i){
        printf("존재하지 않는 정점의 위치입니다.");
        return ;
    }
    
    else{
        int alpha, beta;
        alpha = data;
        beta = data2;
        
        grapeVer *origin;
        origin = (grapeVer*)malloc(sizeof(grapeVer));
        origin->data = beta;
        
        origin->link = C->array[a];
        C->array[a] = origin;
        
        grapeVer *origin2;
        origin2 = (grapeVer*)malloc(sizeof(grapeVer));
        origin2->data = alpha;
        
        origin2->link = C->array[b];
        C->array[b] = origin2;
        
        
    }
    
    
    return ;
}

void Printf_Grape(grape_main*C){
    grapeVer *temp;
    int k =0;
    while(k<i){
        temp =C->array[k];
        while(temp->link !=NULL){
            printf("%d <- ",temp->data);
            temp =temp->link;
        }
        printf("%d\n ",temp->data);
        k++;
    }
}

int main(void){
    grape_main *C;
    C =Make_graph();
    int a = Make_ver(C,100);
    int b = Make_ver(C,90);
    int c = Make_ver(C,80);
    int d = Make_ver(C,70);
    int e = Make_ver(C,60);
    printf("%d %d %d %d %d",a,b,c,d,e);
    
    // 나열할때 순서 신경써서 나열하자
    Make_Edge(C,a,b,100,90);
    Make_Edge(C,b,c,90,80);
    Make_Edge(C,b,d,90,70);
    Make_Edge(C,a,d,100,70);
    Make_Edge(C,c,d,80,70);
    
    
    printf("\n%d\n",i);
    Printf_Grape(C);
}
