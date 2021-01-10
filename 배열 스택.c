// 순차 자료구조로 스택표현

#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int top;
int stack[MAX];


void Reset_Stack(){
    int i =0;
    for(i=0;i<MAX;i++){
        stack[i] = 0;
    }
}

void Push_Stack(int data){
    stack[++top] = data; 
}

int Delete_Stack(){
    if(top == -1){
        printf("순차 리스트 안에 데이터가 존재하지 않습니다.");
        return 0;
    }
    
    int data = stack[top];
    top--;
    if(top== -1 ){
        printf("순차 리스트안에 더이상 데이터가 존재하지 않습니다.");
        return data;
    }
    return data;

}

int Searching_Top(){
    if(top==-1){
        printf("현재 순차 리스트안에 데이터가 존재하지 않습니다.");
        return 0;
    }
    int data = stack[top];
    return data;
}

void Printf_Data(){
    if(top==-1){
        printf("현재 순차 리스트안에 데이터가 존재하지 않습니다.");
        return;
    }
    int i =0;
    for(i=0;i<=top;i++){
        printf(" %d ", stack[i]);
    }
    return;
}

int main(void){
    top = -1;
    Reset_Stack();

    Push_Stack(1);
    Push_Stack(2);
    Push_Stack(3);
    Push_Stack(4);
    Push_Stack(5);
    Push_Stack(6);
    Push_Stack(7);
    Push_Stack(8);
    Push_Stack(9);
    Push_Stack(10);
    Push_Stack(11);
    Printf_Data();
    printf("\n %d \n ",Searching_Top());
    printf("%d ",Delete_Stack());
    printf("\n");
    Printf_Data();
    printf("\n");
    printf(" %d\n ",Delete_Stack());
    Printf_Data();
    
    
}
