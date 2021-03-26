#include <stdio.h>
#include <stdlib.h>
#define size 8

// 병합 정렬
int sort[size];

void merge_sort_A(int list[],int start,int last){
    int a = start;
    int middle = (start+last)/2;
    int b = middle+1;
    int j= start;

    
    

    while(a<=middle&&b<=last){
        if(list[a]<=list[b]){
            sort[j] = list[a];
            j++;
            a++;
            
        }
        else{
            sort[j] = list[b];
            j++;
            b++;
        }
    }
    if(a>middle){
        while(b<=last){
            sort[j] = list[b];
            b++;
            j++;
        }
    }
    else{
        while(a<=middle){
            sort[j] = list[a];
            a++;
            j++;
        }
    }



    for(int k = start; k<=last;k++){
        list[k] = sort[k];
    }
    
    printf("\n");
    for(int i=start;i<=last;i++){
        printf(" %d ",list[i]);
    }
    printf("\n");
}

void merge_sort_B(int list[],int start,int last){
    int middle = (start+last)/2;
    if(last-start>1){
        merge_sort_B(list,start,middle);
        merge_sort_B(list,middle+1,last);
    }
    merge_sort_A(list,start,last);
}



int main(void){
    int list[size] = {15,3,12,6,25,37,13,64};
    merge_sort_B(list,0,7);
}
