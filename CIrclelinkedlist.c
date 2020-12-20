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
        while(temp->link != NULL){
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
    
    if(temp->data == data){
        value = temp->data;
        printf("마지막 노드를 삭제하였습니다.\n이제 노드가 존재하지 않습니다.");
        free(temp);
    }
    if(temp->link->data == data){
        value =temp->link->data;
        A->head = temp;
        temp->link = A->head;
        printf("노드가 한개 남았습니다.");
        return value; 
    }
    while(temp->link->data != data){
        if(temp->link->data == data){
            value = temp->link->data;
            delete = temp->link;
            temp->link = delete->link;
            free(delete);
            break;
        }
    }
    return value;
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
    int i =1;
    while (temp->link != A->head){
        i++;
    }
    return i;
}
