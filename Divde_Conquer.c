// 병합정렬 자료구조

#include <stdio.h>
#define MAX 8  // 배열길이 나타내기

int sorted[MAX];

void Conquer(int list[],int start,int last){
    int i,j,k,temp;
    i = start;
    int mid = (start+last)/2;
    j = (start+last)/2 +1;
    k = last;
    temp = start;
    
    while((i<=mid) && (j<=k)){
        if(list[i]<list[j]) {sorted[temp] = list[i]; i++; temp++;}
        
        else if(list[i]>=list[j]){sorted[temp]=list[j]; j++; temp++;}
    }
    
    if(i==mid+1) {
        for(;j<=k;){
            sorted[temp] = list[j];
            temp++;
            j++;
        }
    }
    else{
        for(;i<j;i++){
            sorted[temp] = list[i];
            temp++;
        }
    }
    for(i=0; i<=last; i++) list[i] = sorted[i];
    
    for(i=0; i<=last;i++){
        printf(" %d ",sorted[i]);
    }
    printf("\n");
}

void Divide_Conquer(int list[], int start, int last){
    if(start<last){
        int mid = (start+last)/2;
        Divide_Conquer(list,start,mid);
        Divide_Conquer(list,mid+1,last);
        Conquer(list,start,last);
    }
}






int main(void){
    int list_a[MAX] = {12,32,52,72,42,62,82,22};
    Conquer(list_a,0,7);
    printf("\n");
    Divide_Conquer(list_a,0,7);
}
