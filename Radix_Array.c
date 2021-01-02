// 기수 정렬

#include <stdio.h>
#include <stdlib.h>
#define Digit 10 // 10진수이기에 10을쓴다. -> 숫자나눔을 위해서.
#define MAX 8
#define HIGH 2 //최대 자리수 표현 69 -> 2자리수



typedef struct SNode{
    int data;
    struct SNode* link;
}SNode;

typedef struct{
    SNode *front;
    SNode *reaf;
}front_reaf;


front_reaf* Creat_front_reaf(){
    front_reaf* new;
    new = (front_reaf*)malloc(sizeof(front_reaf));
    new->front = NULL;
    new->reaf = NULL;
    return new;
}

void push(front_reaf*C,int data){
    SNode *new = (SNode*)malloc(sizeof(SNode));
    new->data = data;
    new->link = NULL;

    if(C->reaf ==NULL){
        C->reaf = new;
        C->front = new;
        
    }

    else{
        C->reaf->link = new;
        C->reaf = new;
    
    }
}


int delete_node(front_reaf*C){
    int temp;
    if(C->reaf == NULL){
        return 0;
    }
    else{
        SNode *temp2;
        if(C->front->link ==NULL){
            temp2 = C->front;
            temp = temp2->data;
            C->front = NULL;
            C->reaf =NULL;
            free(temp2);
            temp2 = NULL;
            return temp;
        }
        temp2 = C->front;
        temp = temp2->data;
        C->front = C->front->link;
        free(temp2);
        return temp;
        
    }
}



void Radix_Array(int list_a[], front_reaf* list_b[]){
    int i,j,k,n = 0;
    k = 1;
    for(i=0;i<HIGH;i++){

        for(j=0;j<MAX;j++){
            push(list_b[(list_a[j]/k) % Digit],list_a[j]);
        }
        
        n=0;
        for(j=0;j<Digit;j++){
            
            SNode* temp;
            temp = list_b[j]->front;
            while(temp!=NULL){
                list_a[n] = delete_node(list_b[j]);
                if(list_a[n]!=0){
                    n++;
                }
                temp = temp->link;
            }
        }
        
        k = k *Digit; // 자리수 옮겨주기
        for(j=0; j<MAX;j++){
            printf(" %d ", list_a[j]);
            
        }
        printf("\n");
    }
}



int main(void){
    int list_a[MAX] = {12,24,13,56,54,87,97,45};
    front_reaf* list_b[Digit];
    int i =0;
    for(i=0;i<Digit; i++) {
        front_reaf* temp =(front_reaf*)malloc(sizeof(front_reaf));
        list_b[i]= temp;
        list_b[i]->front = NULL;
        list_b[i]->reaf = NULL;
    }
    
    Radix_Array(list_a, list_b);
}


//
