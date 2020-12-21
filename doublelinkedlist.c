#include <stdio.h>
#include <stdlib.h>

//Double LinkedList 

typedef struct LinkedNode {
    int data;
    struct LinkedNode *llink;
    struct LinkedNode *rlink;
}LinkedNode;

typedef struct LinkHead {
    struct LinkedNode *head;
}LinkHead;

Linkhead* CreateLinkedList() {
    Linkhead *C;
    C =(Linkhead*)malloc(sizeof(linkhead));
    C->head = NULL;
}

//노드 생성

void CreateNode(Linkhead *A, int data){
    LinkedNode *new;
    new =(LinkedNode*)malloc(sizeof(LinkedNode));
    new->data = data;
    
    if(A->head==NULL){
        A->head = new;
        new->rlink = NULL;
        new->llink =NULL;
    }
    else {
        new->rlink = A->head;
        new->llink = NULL;
        A->head->link =new;
        A->head =new;
    }
}

// 원하는 데이터 노드 삭제

int DeleteNode(linkhead *A, int data){
    LinkedNode *new, *temp;
    int value -0;
    temp = A->head;
    if(temp->data == data){
        value = temp->data;
        if(temp->rlink == NULL){
            printf("마지막노드를 삭제합니다");
            free(temp);
            return value
        }
        else {
            A->head = temp->rlink;
            free(temp);
            return value;
        }
    }
    else {
        while(temp->data !=data){
            temp = temp->rlink;
            if(temp->rlink == NULL){
                printf("해당 데이터는 존재하지않습니다.");
                return 0;
            }
        }
        if(temp->rlink == NULL){
            temp->llink->rlink =NULL;
            free(temp);
            return value;
        }
        else {
            temp->llink->rlink = temp->rlink;
            temp->rlink->llink = temp->llink;
            free(temp);
            return value;
        }
    }
    
}

//데이터 찾기
int SearchingDate(linkhead *A, int data){
    LinkedNode *temp;
    int value =0;
    int number =1;
    temp = A->head;
    if(temp->data == data){
        printf("해당 데이터는 %d번째 노드에 있습니다.", number);
        return 1;
    }
    while(temp->data != data){
        temp= temp->rlink;
        if(temp->rlink == NULL){
            printf("해당 데이터는 존재하지 않습니다.");
            return 0;
        }
        number++;
    }
    value = temp->data;
    printf("해당노드는 %d번째 노드에 있습니다.", number);
    return 1;
}

// 노드 갯수알기
int LenNode(linkhead *A){
    LinkedNode *tmep;
    temp =A->head;
    int len =1;

    while(temp->rlink!=NULL){
        temp = temp->rlink;
        len++
    }
    if(temp == A->head){
        return 1;
    }
    else{
        return len;
    }
}