#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;




Node* making_Node(Node* C,int data){
    if(C==NULL){
        Node* new = (Node*)malloc(sizeof(Node));
        new->data = data;
        new->right = NULL;
        new->left = NULL;
        return new;
    }
    Node* temp = C;
    if(temp->data>data){
        temp->left = making_Node(temp->left,data);    
        reblance(C);
        return C;
    }
    else{
        temp->right = making_Node(temp->right,data);
        reblance(C);
        return C;
    }
}

void Printf_tree(Node* C){
    if(C==NULL){
        return;
    }
    Printf_tree(C->left);
    printf(" %d ",C->data);
    Printf_tree(C->right);
}

// AVL 구현
int get_number(Node*C){
    int a=0;
    int b=0;
    Node* temp = C;
    while(temp->right!=NULL){
        b++;
        temp = temp->right;
    }
    temp =C;
    while(temp->left!=NULL){
        a++;
        temp = temp->left;
    }
    return a-b;
}
void LL_rotate(Node*C){
    int a = C->data;
    int b = C->left->data;
    Node* temp = C->left;
    C->data = b;
    temp->data = a;
    C->left = temp->left;
    C->right = temp;
}

void RR_rotate(Node*C){
    int a = C->data;
    int b = C->right->data;
    Node* temp = C->right;
    temp->data = a;
    C->data = b;
    C->right = temp->right;
    C->left = temp;
}

void reblance(Node*C){
   
    int height = get_number(C);
    if(1>=height>=-1){
        return;
    }

    if(height>1){
        printf("+_1");
        if(get_number(C->left)>0){
            LL_rotate(C);
            return;
        }
        RR_rotate(C->left);
        LL_rotate(C);
        
        return;
    }
    return;
}




int main(void){
    Node* C = NULL;
    C= making_Node(C,30);
    making_Node(C,20);
    making_Node(C,10);
    making_Node(C,5);
    //making_Node(C,15);
    //making_Node(C,25);
    //making_Node(C,35);
    //making_Node(C,45);
    //making_Node(C,40);
    //making_Node(C,50);
    Printf_tree(C);
    printf("\n%d",get_number(C));
}

