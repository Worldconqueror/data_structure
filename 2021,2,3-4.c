#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* right;
    struct Node* left;
}Node;

typedef struct {
    Node* front;
    Node* reaf;
}deque;

deque* Making_deque(){
    deque* C =(deque*)malloc(sizeof(deque));
    C->front =NULL;
    C->reaf =NULL;
    return C;
}

//reaf 에 넣기
void add_data_reaf(deque*C, int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data =data;
    new->right =NULL;
    new->left =NULL;
    if(C->front ==NULL){
        C->front =new;
        C->reaf = new;
        return;
    }
    new->right = C->reaf;
    C->reaf->left = new;
    C->reaf = new;
    printf_deque(C);
    return;
}

//front 에 넣기
void add_data_front(deque* C,int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data =data;
    new->right =NULL;
    new->left =NULL;
    if(C->front==NULL){
        C->front =new;
        C->reaf = new;
        return;
    }
    new->left = C->front;
    C->front->right =new;
    C->front = new;
    printf_deque(C);
    return;
}

void printf_deque(deque*C){
    if(C->front ==NULL){
        printf("데큐가 비어있습니다.\n");
        return;
    }
    Node* temp = C->reaf;
    printf("deque = [");
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp = temp->right;
        if(temp==NULL){
            printf("]\n");
            return;
        }
    }
}

//reaf 에서 빼기
void delete_data_reaf(deque*C){
    Node* temp = C->front;
    Node* temp2 = C->reaf;
    if(temp==NULL){
        printf("deque가 비었습니다.\n");
        return;
    }
    if(temp==temp2){
        C->front=NULL;
        C->reaf =NULL;
        free(temp);
        temp=NULL;
        printf_deque(C);
        return;
    }
    while(temp->left!=temp2){
        temp = temp->left;
    }
    temp->left =NULL;
    C->reaf = temp;
    printf("삭제한 데이터: %d\n ",temp2->data);
    free(temp2);
    temp2=NULL;
    printf_deque(C);
    return;
}
//front 에서 빼기

void delete_data_front(deque* C){
    Node* temp = C->front;
    Node* temp2 = C->reaf;
    if(temp==NULL){
        printf("deque가 비었습니다.\n");
        return;
    }
    if(temp==temp2){
        C->front=NULL;
        C->reaf =NULL;
        free(temp);
        temp=NULL;
        printf_deque(C);
        return;
    }
    while(temp2->right!=temp){
        temp2 = temp2->right;
    }
    C->front =temp2;
    temp2->right=NULL;
    printf("삭제한 데이터: %d\n",temp->data);
    free(temp);
    temp=NULL;
    printf_deque(C);
    return;
}


int main(void){
    deque* C = Making_deque();
    add_data_front(C,21);
    add_data_front(C,85);
    add_data_front(C,13);
    add_data_front(C,34);
    add_data_front(C,56);
    add_data_reaf(C,22);
    delete_data_reaf(C);
    delete_data_front(C);
    delete_data_reaf(C);
    delete_data_front(C);
    delete_data_reaf(C);
    delete_data_reaf(C);
    
    
}


