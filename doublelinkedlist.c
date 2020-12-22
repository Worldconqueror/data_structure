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

LinkHead* CreateLinkedList() {
    LinkHead *C;
    C =(LinkHead*)malloc(sizeof(LinkHead));
    C->head = NULL;
    return C;
}

//노드 생성

void CreateNode(LinkHead *A, int data){
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
        A->head->llink =new;
        A->head =new;
    }
}

// 원하는 데이터 노드 삭제

int DeleteNode(LinkHead *A, int data){
    LinkedNode  *temp;
    int value =0;
    temp = A->head;
    if(temp->data == data){
        value = temp->data;
        if(temp->rlink == NULL){
            printf("마지막노드를 삭제합니다");
            temp->data = value;
            free(temp);
            return value;
        }
        else {
            A->head = temp->rlink;
            value = temp->data;
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
            value = temp->data;
            free(temp);
            return value;
        }
        else {
            temp->llink->rlink = temp->rlink;
            temp->rlink->llink = temp->llink;
            value = temp->data;
            free(temp);
            return value;
        }
    }
    
}

//데이터 찾기
void SearchingDate(LinkHead *A, int data){
    LinkedNode *temp;
    int number =1;
    temp = A->head;
    if(temp->data == data){
        printf("해당 데이터는 %d번째 노드에 있습니다.", number);
        
    }
    while(temp->data != data){
        temp= temp->rlink;
        if(temp->rlink == NULL){
            printf("해당 데이터는 존재하지 않습니다.");
            
        }
        number++;
    }
    
    printf("해당노드는 %d번째 노드에 있습니다.", number);
    
}

// 노드 갯수알기
int LenNode(LinkHead *A){
    LinkedNode *temp;
    temp =A->head;
    int len =1;

    while(temp->rlink!=NULL){
        temp = temp->rlink;
        len++;
    }
    if(temp == A->head){
        return 1;
    }
    else{
        return len;
    }
}
void printf_Node(LinkHead *C){
    LinkedNode *temp;
    temp = C->head;
    while(1){
        if(temp->rlink == NULL){
            printf(" %d ",temp->data);
            return;}
        else{
            printf(" %d ",temp->data);
            temp= temp->rlink;
            
            }
        
    }
    return ;
}

int main(void){
    LinkHead *C;
    C = CreateLinkedList();
    CreateNode(C,10);
    CreateNode(C,20);
    CreateNode(C,30);
    CreateNode(C,40);
    printf_Node(C);
    printf("\n");
    SearchingDate(C,20);
    int i;
    i = DeleteNode(C,20);
    printf("\n%d\n",i);
    printf_Node(C);
}
