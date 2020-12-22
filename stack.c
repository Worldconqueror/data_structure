// How to make stack data structure


#include <stdio.h>
#include <stdlib.h>
typedef struct StackData{
    int data;
    struct StackData *link;
}StackData;

typedef struct HeadStack{
    StackData *top;
}HeadStack;

HeadStack* CreateTop(){
    HeadStack *C;
    C = (HeadStack*)malloc(sizeof(HeadStack));
    C->top = NULL;
    return C;
}

void Create(HeadStack* A,int data){
    StackData *new;
    new = (StackData*)malloc(sizeof(StackData));
    new->data = data;
    if(A->top == NULL) {
        A->top=new;
    }

    else{
        new->link = A->top;
        A->top = new;
    }
}

int PopStack(HeadStack*A){
    StackData *temp;
    int value;
    if(A->top ==NULL) {
        printf("스택이 비었습니다.");
        return 0;
    }
    else {
        temp = A->top;
        value = temp->data;
        A->top = temp->link;
        free(temp);
        return value;
    }
}

int lenStack(HeadStack *A){
    StackData *temp;
    temp = A->top;
    int number = 1;
    while(temp->link != NULL) {
        number++;
        temp = temp->link;
    }
    return number;
}

void Printf_Stack(HeadStack *A){
    StackData *c;
    c =A->top;
    printf("[  ");
    while(c->link !=NULL){
        printf("  %d  ",c->data);
        c = c->link;
    }
    if(c->link ==NULL){
        printf("  %3d ]", c->data);
    }
}


int main(void) {
    HeadStack* C;
    int data__;

    C= CreateTop();
    
    Create(C,10);
    Create(C,11);
    Create(C,13);
    Create(C,14);
    Create(C,15);
    Create(C,16);
    Create(C,17);
    Create(C,18);
    Create(C,19);
    
    Printf_Stack(C);   //[10 11 13 14 15 16 17 18 19 ]
    data__ = PopStack(C);    
    printf("%d",data__); //10

    Printf_Stack(C); //[11 13 14 15 16 17 18 19]
}
