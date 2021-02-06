#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a>b ? a:b)

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;

}Node;

Node* making_tree(Node* C,int data){
    if(C==NULL){
        Node* new = (Node*)malloc(sizeof(Node));
        new->data = data;
        new->right =NULL;
        new->left =NULL;
        return new;
    }
    if(data>C->data){
        C->right = making_tree(C->right,data);
        return C;
    }
    C->left = making_tree(C->left,data);
    return C;
}

void printf_tree_front(Node* C){
    if(C==NULL){
        return;
    }
    printf(" %d ",C->data);
    printf_tree_front(C->left);
    printf_tree_front(C->right);
}

void printf_tree_middle(Node* C){
    if(C==NULL){
        return;
    }
    printf_tree_front(C->left);
    printf(" %d ",C->data);
    printf_tree_front(C->right);
}

void printf_tree_reaf(Node*C){
    if(C==NULL){
        return;
    }
    printf_tree_front(C->left);
    printf_tree_front(C->right);
    printf(" %d ",C->data);
}


Node* Searching_Node(Node*C, int data){
    if(C==NULL){
        printf("트리가 비어있습니다.");
        return NULL;
    }
    Node* temp = C;
    do{
        if(temp->data==data){
            printf("\n찾았습니다. ");
            return temp;
        }
        if(temp->data>data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
        

    }while(temp!=NULL);
    printf("찾지 못했습니다! 존재하지않는 데이터입니다.\n");
    return NULL;
}
Node* Searching_parent(Node*C,Node*target){
    Node* temp = C;
    Node* temp2 = temp;
    if(C==target){
        printf("\nroot 노드입니다.\n");
        return C;
    }
    do{
        if(temp->data==target->data){

            return temp2;
        }
        if(temp->data>target->data){
            temp2=temp;
            temp = temp->left;
            
        }
        else{
            temp2 =temp;
            temp = temp->right;
        }
        
    }while(temp!=NULL); 
}



void Delete_tree_Node(Node* C,Node* target){
    

    if(target->left==NULL&&target->right==NULL){
        Node* temp;
        temp = Searching_parent(C,target);
        if(temp->left ==target){
            temp->left = NULL;
            free(target);
            target = NULL;
            return;
        }    
        temp->right =NULL;
        free(target);
        target=NULL;
        return;
    }
    if(target->left!=NULL&&target->right!=NULL){
        Node* target_parent = Searching_parent(C,target);
        Node* temp =target->left;
        Node* parent = target;
        if(temp->right==NULL){
            temp= target->right;
            while(temp->left!=NULL){
                temp =temp->left;
            }
            if(temp==target->right){
                target->data = temp->data;
                target->right=NULL;
                free(temp);
                temp=NULL;
                return;
            }
            Node *b = Searching_parent(C,temp);
            b->left = NULL;
            target->data = temp->data;
            free(temp);
            temp=NULL;
            return;
        }
        while(temp->right!=NULL){
            temp = temp->right;
        }
        int data = temp->data; 
        if(temp->left!=NULL){
            Node* ee = Searching_parent(C,temp);
            ee->right = temp->left;
        }
        else{
            Node* ee = Searching_parent(C,temp);
            ee->right = NULL;
        }
        target->data = data;
        free(temp);
        temp=NULL;
        return;
    }

    Node* a = Searching_parent(C,target);
    if(target->right!=NULL){
        if(a->data>target->data){
            a->left = target->right;
            free(target);
            target=NULL;
            return;
        }
        a->right = target->right;
        free(target);
        target=NULL;
        return;
    }
    if(a->data>target->data){
            a->left = target->left;
            free(target);
            target=NULL;
            return;
        }
        a->right = target->left;
        free(target);
        target=NULL;
        return;
}




int main(void){
    //root 생성
    Node* C = NULL;
    C = making_tree(C,40);
    making_tree(C,60);
    making_tree(C,30);
    making_tree(C,35);
    making_tree(C,25);
    making_tree(C,50);
    making_tree(C,37);
    making_tree(C,34);
    making_tree(C,65);
    making_tree(C,75);
    making_tree(C,64);
    printf_tree_front(C);
    Node* target =Searching_Node(C,40);
    Delete_tree_Node(C,target);
    printf("\n");
    printf_tree_front(C);
    
}
