
// CircleLinkedlist //
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode{
    int data;
    struct LinkedNode *link;
} LinkedNode;

typedef struct headNode {
    LinkedNode *head;
}headNode;

headNode* CreateHead() {
    headNode *C;
    C = (headNode*)malloc(sizeof(headNode));
    C->head = NULL;
    return C;
}

void CreateNode(headNode* A, int data) {
    LinkedNode *newnode;
    LinkedNode *temp;
    newnode = (LinkedNode*)malloc(sizeof(LinkedNode));
    newnode->data = data;
    newnode->link = NULL;
    
    if(A->head ==NULL){
        A->head = newnode;
        newnode->link = newnode; //SimpleLinkeedList 와 CircleLinkedList 의 차이점
    }
    else {
        temp = A->head;
        while(temp->link != A->head){
            temp = temp->link;
        }
        temp->link = newnode;         // CircleLinkedList 생성
        newnode->link = A->head;
    }
}

void Print_Node(headNode*A) {
    LinkedNode *temp;
    temp = A->head;
    printf("모든 데이터 출력 : [ ");
    while(1) {
        printf(" %d  ", temp->data);
        temp = temp->link;
        if(temp == A->head){
            printf(" ]");
            break;
        }
    }
}

int Delte_data(headNode*A, int data){
    LinkedNode *temp;
    LinkedNode *delete;
    temp = A->head;
    int value = 0;
    
    if (temp->data ==data){
        delete = A->head;
        while(1){
            if(temp->link == delete){
                break;
            }
            temp = temp->link;
        }
        A->head = delete->link;
        temp->link = A->head;
        value = delete->data;
        free(delete);
        delete = NULL;
        return value;
    }
    else {
        while(1){
            if(temp->link->data ==data){
                delete = temp->link;
                temp->link = delete->link;
                value = delete->data;
                free(delete);
                delete =NULL;
                return value;
            }
            temp = temp->link;
            if(temp->link->data == A->head->data){
                return 0;
            }
            
        }
        
        
        return value;
    }
    
} 

int SearchingValue(headNode *A, int data){
    LinkedNode *temp;
    temp = A->head;
    int i = 0;
    if(data ==0) {
        return 0;
    }
    if(temp->data == data){
        printf("1번째 노드입니다.");
        return 1;
    }
    while (temp->link != A->head){
        i++;
        if(temp->data == data){
            printf("%d번째 노드의 data 값입니다.", i);
            return 1;
        }
        temp = temp->link;
    }
    printf("해당 데이터는 현재 리스트에 존재하지 않습니다.");
    return 0;
}

int HowManyNode(headNode*A){
    LinkedNode *temp;
    temp = A->head;
    int i =0;
    if(temp ==NULL){
        return 0;
    }
    if(temp->link == A->head){
        return 1;
    }
    while (1){
        i++;
        temp = temp->link;
        if(temp->data == A->head->data){
            return i;
        }
    
    }
}

int main(void){
    headNode *C;
    C =CreateHead();
    CreateNode(C,10);
    CreateNode(C,20);
    CreateNode(C,30);
    CreateNode(C,40);
    CreateNode(C,50);
    Print_Node(C);
    int i;
    i =HowManyNode(C);
    printf("\n%d",i);
    
    i = Delte_data(C,30);
    printf("\n%d\n",i);
    i =HowManyNode(C);
    printf("\n%d\n",i);
    Print_Node(C);
    
}
