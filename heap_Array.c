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

   

void heap_array(heap* C,int list[]){
    int i =0;

    for(i=0;i<MAX;i++){
        Make_heapTRee(list[i],C);
    }    
    printf_heap(C);
    for(i=0;i<MAX;i++){
        printf(" %d ",Delete_heapTRee(C));
    }
    printf(" \n ");
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
    int list[MAX] = {12,52,32,15,53,64,25,69,25,31};

    heap_array(C,list);
}
