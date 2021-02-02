// 연결리스트, 원형 연결리스트, 이중연결리스트 //
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}Node;

typedef struct Node_head{
    Node* link;
}Node_head;

Node_head* making_head(){
    Node_head* C = (Node_head*)malloc(sizeof(Node_head));
    C->link = NULL;
    return C;
}

void add_node(Node_head* C,int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->link = NULL;
    if(C->link == NULL){
        C->link = newnode;
        return;
    }
    newnode->link = C->link;
    C->link = newnode;
    return ;
}
Node* searching_node(Node_head* C,int data){
    Node* temp;
    temp = C->link;
    
    if(temp==NULL){
        printf("리스트가 비었습니다.");
        return temp;
    }

    while(temp != NULL){
        if(temp->data == data){
            return temp;
        }
        if(temp->link == NULL){
            printf("존재하지않습니다.");
            return C->link;
        }
        temp = temp->link;
    }
    return temp;
}


void delete_node(Node_head* C, Node* delete){
    Node* temp;
    temp = C->link;
    if(temp == delete){
        free(delete);
        delete = NULL;
        C->link = NULL;
        return;
    }
    if(delete->link==NULL){
        while(temp->link!=delete){
            temp = temp->link;
        }
        temp->link =NULL;
        free(delete);
        delete =NULL;
        return;
    }
    while(temp->link!=delete){
        temp = temp->link;
    }
    temp->link = delete->link;
    free(delete);
    delete =NULL;
    printf_link(C);
    return;
}

void printf_link(Node_head* C){
    Node* temp;
    temp = C->link;
    printf("리스트의 원소 = [");
    while(temp !=NULL){
        printf(" %d ",temp->data);
        temp = temp->link;
        if(temp ==NULL){
            printf("]\n");
            return;
        }
    }
}




int main(void){
    Node_head* C= making_head();
    add_node(C,25);
    add_node(C,12);
    add_node(C,35);
    add_node(C,41);
    printf_link(C);
    Node* temp = searching_node(C,35);
    delete_node(C,temp);
}
