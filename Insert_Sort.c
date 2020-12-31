// 삽입정렬
// 계속앞으로 작은수 밀어주는 형식이다.
#include <stdio.h>

void Insert_Sort(int list[], int len){
    int i, j, temp;
    for(i=1; i<len; i++){
        temp = list[i];
        j = i;
        while((list[j-1]>temp) && (j>0)){
            list[j] = list[j-1];
            j = j-1;
        }
        list[j] = temp;
    }
}



int main(void){
    int list_a[6] = {124,231,244,12,141,127};
    Insert_Sort(list_a,6);
    int i =0;
    for(i=0;i<6;i++){
        printf(" %d ",list_a[i]);
    }
}
