#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct {
    Node* head;
}Node_head;

Node_head* Making_head(){
    Node_head* C = (Node_head*)malloc(sizeof(Node_head));
    C->head = NULL;
    return C;
}

void add_data(Node_head *C,int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->right =NULL;
    new->left = NULL;
    if(C->head ==NULL){
        C->head = new;
        return;
    }
    Node* temp;
    temp = C->head;
    new->right = temp;
    temp->left = new;
    C->head = new;
    return;
}

void print_list(Node_head* C){
    printf("list = [");
    Node* temp = C->head;
    if(temp ==NULL){
        printf("리스트가 비었습니다.\n");
        return;
    }
    while(temp->right!=NULL){
        printf(" %d ",temp->data);
        temp = temp->right;
        if(temp->right==NULL){
            printf(" %d ",temp->data);
            printf("]");
            return;
        }
    }
}

Node* Searching_list(Node_head*C,int data){
    if(C->head==NULL){
        printf("\n리스트가 비었습니다.");
        return C->head;
    }
    Node* temp= C->head;
    while(temp->right!=NULL){
        if(temp->data==data){
            printf("\n발견했습니다.\n");
            return temp;
        }
        temp = temp->right;
    }
    if(temp->data==data){
            printf("\n발견했습니다.\n");
            return temp;
    }
    printf("\n발견하지 못했습니다.\n");
    return C->head;
}

void delete_Node(Node_head* C, Node* target){
    Node* temp = C->head;
    if(temp == target){
        C->head = target->right;
        free(target);
        target = NULL;
        print_list(C);
        return;
    }
    // target이 마지막 노드라면
    if(target->right ==NULL){
        target->left->right = NULL;
        free(target);
        target=NULL;
        print_list(C);
        return;
    }
    while(temp->right!=target){
        temp = temp->right;
    }
    temp->right = target->right;
    target->right->left = temp;
    free(target);
    target = NULL;
    print_list(C);
    return;
    
}

int main(void){
    Node_head* C = Making_head();
    add_data(C,24);
    add_data(C,12);
    add_data(C,51);
    add_data(C,23);
    print_list(C);
    Node* temp = Searching_list(C,12);
    delete_Node(C,temp);
}
