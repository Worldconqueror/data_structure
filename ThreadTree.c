// 스레드 트리 만들기 (재귀호출 사용하지 않은 노드 표현)
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode{
    int data;
    struct TNode*right;
    struct TNode*left;
    int Thread;
}TNode;

TNode* Makeing_Root(int data,TNode* left, TNode* right, int Thread){
    TNode* new = (TNode*)malloc(sizeof(TNode));
    new-> data =data;
    new->right = right;
    new->left = left;
    new->Thread = Thread; //Thread 는 1이나 0으로 구분, 1 --> 존재, 0 --> 존재 x
    return new;
}

TNode* IsThread(TNode* p){
    TNode* q = p->right;
    if(q==NULL) return q;
    if(p->Thread==1) return q;
    else {
        while(q->left !=NULL){
            q = q->left;
            return q;
        }
    }

    return q;    
}


int main(){
    TNode* G1 = Makeing_Root(4,NULL,NULL,1);
    TNode* G2 = Makeing_Root(5,NULL,NULL,1);
    TNode* G3 = Makeing_Root(6,NULL,NULL,1);
    TNode* G4 = Makeing_Root(7,NULL,NULL,0);
    TNode* G5 = Makeing_Root(3,G1,G2,0);
    TNode* G6 = Makeing_Root(2,G3,G4,0);
    TNode* G7 = Makeing_Root(1,G5,G6,0);

    G1->right = G5;
    G2->right = G7;
    G3->right = G6;

    TNode *temp = G7;
    
    while(temp->left !=NULL){
        temp = temp->left;
    }
    
    do{
        printf(" %d ",temp->data);
        temp = IsThread(temp);
    }while(temp);
    
    
}
