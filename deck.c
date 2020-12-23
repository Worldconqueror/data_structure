// deck 연결리스트 잡기

#include <stdio.h>
#include <stdlib.h>

typedef struct DeckData{
    int data;
    struct DeckData *llink;
    struct DeckData *rlink;
}DeckData;

typedef struct DeckLine{
    DeckData *back;
    DeckData *front;
}DeckLine;

DeckLine* CreateDeckLine(){
    DeckLine *C;
    C =(DeckLine*)malloc(sizeof(DeckLine));
    C->back = NULL;
    C->front =NULL;
    return C;
}

// front 앞에 넣기
void InReaf(DeckLine *C,int data){
    DeckData *new;
    new = (DeckData*)malloc(sizeof(DeckData));
    new->data = data;
    if(C->front ==NULL){
        C->front = new;
        C->back = new;
        new->llink = NULL;
        new->rlink =NULL;
    }
    else {
        new->rlink = C->front;
        C->front->llink = new;
        C->front = new;
        DeckData *temp;
        temp = C->front;
        while(temp->rlink != NULL){
            temp = temp->rlink;
        }
        C->back = temp;
    }
}

// front 앞에서 빼기
void OutReaf(DeckLine *C) {
    if(C->front == NULL){
        printf("노드가 존재하지 않습니다.");
    }
    else {
        DeckData *temp;
        int value;
        temp = C->front;
        value = temp->data;
        C->front = temp->rlink;
        free(temp);
        printf("삭제한 데이터 -> %d\n",value);
    }
}

// back 앞에서 넣기
void InBack(DeckLine*C, int data){
    DeckData *new;
    new = (DeckData*)malloc(sizeof(DeckData));
    new->data = data;
    if(C->front ==NULL){
        C->back = new;
        C->front = new;
        new->llink = NULL;
        new->rlink = NULL;
    }
    else{
        C->back->rlink = new;
        new->llink = C->back;
        C->back = new;
    }
}
// back 앞에서 빼기
void OutBack(DeckLine*C){
    if(C->front == NULL){
        printf("노드가 존재하지 않습니다.");
    }
    else {
        DeckData *temp;
        int value;
        temp = C->back;
        C->back = temp->llink;
        value = temp->data;
        printf("삭제한 데이터 -> %3d\n",value);
        free(temp);
        temp = NULL;
        return;
    }

}

void printf_data(DeckLine*C){
    DeckData* temp;
    temp = C->front;
    while(temp !=C->back){
        printf(" %d ",temp->data);
        temp = temp->rlink;
    }
    printf(" %d ", temp->data);
}


int main(void){
    DeckLine *C;
    C = CreateDeckLine();
    InReaf(C,10);
    InReaf(C,20);
    InReaf(C,30);
    InReaf(C,40);
    OutReaf(C);
    InBack(C,-10);
    InBack(C,-20);
    InBack(C,-30);
    InBack(C,-40);
    printf_data(C);
    printf("\n");
    OutBack(C);
    printf_data(C);
}
