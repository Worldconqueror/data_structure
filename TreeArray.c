// 트리정렬
//리스트에 중복되는 값 존재 xxx여야한다.
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct TNode{
    int data;
    struct TNode* left;
    struct TNode* right;
}TNode;
typedef struct Root_TNode{
    struct TNode* link;
}Root_TNode;



// 리스트에 있는 데이터값들 노드에 박아넣기

TNode* Data_Push(TNode* C,int data){
    
    if(C ==NULL){
        TNode* new = (TNode*)malloc(sizeof(TNode));
        new->data =data;
        new->right = NULL;
        new->left = NULL;
        return new;
    }
    
    if(C->data >data) {
        C->left = Data_Push(C->left,data);
    }
    
    else{
        C->right = Data_Push(C->right, data);
    }
    return C;
}

// 트리에 노드 박아넣은뒤 다시 호출

void Printf_Tree(TNode *C){
    if(C!=NULL){
        Printf_Tree(C->left);
        printf(" %d\n",C->data);
        Printf_Tree(C->right);
    }
}

int main(void){
    int list[MAX];

    TNode* C=NULL;
    
    C = Data_Push(C,rand());
    
    

    int i =0;
    for(i=0;i<MAX;i++){
        list[i] = rand();
    }

    for(i=1;i<MAX;i++){
        
        C = Data_Push(C,list[i]);
        printf("삽입된 랜덤의 수: %d\n ",list[i]);
    }
    Printf_Tree(C);
}
