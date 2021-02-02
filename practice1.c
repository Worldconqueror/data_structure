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
    if(C->link == NULL){
        C->link = newnode;
        newnode->link = C->link;
        return ;
    }
    Node* temp;
    temp = C->link;
    while(temp->link !=C->link){
        temp = temp->link;
    }
    
    newnode->link = C->link;
    C->link = newnode;
    temp->link =C->link;
    return ;
}
Node* searching_node(Node_head* C,int data){
    Node* temp;
    temp = C->link;
    
    if(temp==NULL){
        printf("리스트가 비었습니다.");
        return temp;
    }
    
    if(temp->data == data){
        printf("찾았습니다.");
        return temp;
    }
    
    while(temp->link != C->link){
        if(temp->data == data){
            printf("찾았습니다.");
            return temp;
        }
        
        else if(temp->link == C->link){
            printf("존재하지않습니다.");
            return C->link;
        }
        temp = temp->link;
        //마지막원소 예외처리
        if(temp->data == data){
            printf("찾았습니다.");
            return temp;
        }
    }
}


void delete_node(Node_head* C, Node* delete){
    Node* temp;
    Node* temp2;
    temp = C->link;
    if(temp == delete){
        C->link = C->link->link;
        while(temp->link!=delete){
            temp = temp->link;
        }
        temp->link = C->link;
        free(delete);
        delete = NULL;
        printf_link(C);
        return;
    }
    if(delete->link==temp){
        while(temp->link!=delete){
            temp = temp->link;
        }
        temp->link =C->link;
        free(delete);
        delete =NULL;
        printf_link(C);
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
    while(temp->link !=C->link){
        printf(" %d ",temp->data);
        temp = temp->link;
        if(temp->link ==C->link){
            printf(" %d ",temp->data);
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
    Node* temp2 = searching_node(C,41);
    printf("\n");
    delete_node(C,temp2);
}
