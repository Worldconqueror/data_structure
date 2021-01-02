// 히프 정렬

//1 , 23 ,45, 67
#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //정렬 원소 갯수 저장


typedef struct heap{
    int n;
    int list[MAX];
}heap;

heap* Making_heap(){
    heap* new;
    new = (heap*)malloc(sizeof(heap));
    new->n=0;
    return new;
}

void Make_heapTRee(int data, heap* C){
    C->n++;
    int n = C->n;
    
    C->list[n] = data;
    
    //최대 히프 정리
    while((n>=2) && (data> C->list[n/2])){
        C->list[n] = C->list[n/2];
        n = n/2;
    }
    C->list[n] = data;
}


//최대 히프 삭제 방법 -> 가장 큰수를 삭제한다.
int Delete_heapTRee(heap*C){
    int num = C->list[1];
    int p =1;
    int c =2;
    int temp =C->n;
    C->n--;

    C->list[1] = C->list[temp];

    while(c<=C->n){
        if((c<C->n)&&C->list[c]<C->list[c+1]) c++;
        
        if(C->list[p]>=C->list[c]) {
            C->list[p] = C->list[temp];
            break;
        }
        else{
            int a = C->list[p];
            C->list[p] = C->list[c];
            C->list[c] = a;
            p =c;
            c *= 2;
        }
    }
    return num;
}
   

    
    






void printf_heap(heap* C){
    int i;
    for(i=1;i<=C->n;i++){
        printf(" %d ",C->list[i]);
    }
    printf("\n");
}

int main(void){
    heap* C;
    C= Making_heap();
    Make_heapTRee(1,C);//1
    Make_heapTRee(2,C);//2
    Make_heapTRee(3,C);//3
    Make_heapTRee(4,C);//4
    printf_heap(C);
    Make_heapTRee(5,C);
    Make_heapTRee(6,C);
    Make_heapTRee(7,C);
    Make_heapTRee(8,C);
    Make_heapTRee(9,C);
    Make_heapTRee(10,C);
    printf_heap(C);
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    printf(" %d ", Delete_heapTRee(C));
    
}
