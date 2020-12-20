// SimpleLinked DATA STRUCTURE

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

int howManyNode(headNode* );

void CreateNode(headNode* A, int data) {
    LinkedNode *newnode;
    newnode = (LinkedNode*)malloc(sizeof(LinkedNode));
    newnode->data = data;
    newnode->link = NULL;
    
    if(A->head ==NULL){
        A->head = newnode;
        newnode->link = NULL;
    }
    else {
        newnode->link = A->head;
        A->head = newnode;
    }

}

// 원하는 데이터 삭제
int DeleteNode(headNode *A,int data){
    LinkedNode *temp;
    int value =  0;
    temp = A->head;
    LinkedNode *deleteNode;
    
    while (temp->link != NULL){
        if(temp->link->data !=data){
            temp = temp->link;
        }
        else if (temp->link->data == data){
            value = temp->link->data;
            break;
        }
    }
    if (temp->link->link == NULL) {
        free(temp->link);
    }
    else {
        deleteNode = temp->link;
        temp->link = temp->link->link;
        free(deleteNode);
    }

    return value;
    }


// 전체 노드 갯수 알기
int howManyNode(headNode *A) {
    int a = 0;
    while (A->head !=NULL){
        a++;
        A->head = A->head->link;
    
    }
    return a;
}

// 원하는 데이터 찾기
void SearchDATA(headNode*A, int data){
    LinkedNode *find;
    int len= howManyNode(A);
    int i =1;
    find = A->head;
    for(i=1; i<=len;i++ ){
        if(find->data == data){
            printf("원하는 데이터를 찾았습니다. %d번째 노드의 데이터입니다.",i);
            break;
        }

        if (i==len) {
            printf("원하는 데이터가 존재하지 않습니다.");
            break;
        }    
    }   
}


//  저장된 데이터 내뱉기
void Print_Data(headNode *A) {
    int i = 0;
    if(A->head == NULL){
        printf("노드가 존재하지 않습니다.");
    }

    while(A->head != NULL){
        i++;
        printf("%d번째 노드에 해당하는 데이터는 %d 입니다.\n",i,A->head->data);
        A->head = A->head->link;
    }
}






int main(void) {    
    headNode *C;
    int len = 0;
    int DeleteData;
    C = CreateHead();

    CreateNode(C,123);
    CreateNode(C,40);
    CreateNode(C,30);
    CreateNode(C,20);
    CreateNode(C,10);
    CreateNode(C,70);
    CreateNode(C,60);
    CreateNode(C,100);
    
    len = howManyNode(C);
    printf("%d",len);
    SearchDATA(C, 10);
    Print_Data(C);
    DeleteData = DeleteNode(C, 100);
    printf("제거된 데이터: %d",DeleteData);
    Print_Data(C);

}