#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX(a,b) ((a>b) ? a:b)

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

int get_number(Node* target){
    int height = 0;
    if(target!=NULL) height = MAX(get_number(target->left) , get_number(target->right)) +1;
    return height;
}

int get_BF(Node* C){
    if(C == NULL){
        return 0;
    }
    return get_number(C->left) - get_number(C->right);
}

Node* LL_array(Node* target){
  
        Node* temp = target->left;
        target->left = temp->right;
        temp->right = target;
        return temp;
    
}

Node* RR_array(Node*target){
    
        Node* temp = target->right;
        target->right = temp->left;
        temp->left = target;
        return temp;
    
}

Node* LR_array(Node* target){
    
        Node* temp =target->left;
        target->left = RR_array(temp);
        return LL_array(target);
    
}

Node* RL_array(Node* target){
    
        Node* temp = target->right;
        target->right = LL_array(temp);
        return RR_array(target);
    
    
}


Node* rebalance(Node**p){
    int a = get_BF(*p);

    if(a>1){
        if(get_BF((*p)->left) > 0){
            *p = LL_array(*p);
        }
        else *p = LR_array(*p);
    }
    
    else if(a<-1){
        if(get_BF((*p)->right) < 0){
            *p = RR_array(*p);
        }
        else *p = RL_array(*p);
    }
    return *p;
}


Node* making_AVL(Node** C, int data){
    if(*C==NULL){
        *C = (Node*)malloc(sizeof(Node));
        (*C)->data = data;
        (*C)->left = NULL;
        (*C)->right = NULL;
    }
    else if((*C)->data >data){
        (*C)->left = making_AVL(&((*C)->left),data);
        *C= rebalance(C);
    }
    else if((*C)->data <data){
        (*C)->right = making_AVL(&((*C)->right),data);
        *C = rebalance(C);
    }
    return *C;
}

void display_AVLtree(Node* C){
    if(C!=NULL){
        display_AVLtree(C->left);
        printf(" %d ",C->data);
        display_AVLtree(C->right);
    }
}

void searching_data(Node*C, int data){
    if(C==NULL) {
        printf(" 트리가 존재하지 않습니다.\n");
        return;
    }
    Node* temp = C;
    int i = 1;
    while(temp!=NULL){
        if(temp->data == data){
            printf("%d 번째만에 찾았습니다! \n",i);
            return;
        }
        if(temp->data > data){
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
        
        
        i++;
    }
    if(temp==NULL){
        printf("못찾았습니다!\n %d번 시도",i);
    }
}




int main(void){
    Node* C =NULL;
    C = making_AVL(&C,10);
    making_AVL(&C,20);
    making_AVL(&C,30);
    making_AVL(&C,40);
    making_AVL(&C,50);
    making_AVL(&C,60);
    making_AVL(&C,70);
    making_AVL(&C,80);
    making_AVL(&C,90);
    making_AVL(&C,100);
    display_AVLtree(C);
    searching_data(C,100);
 
}
