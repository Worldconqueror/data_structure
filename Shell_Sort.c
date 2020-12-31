// 쉘 정렬
// 간격을둬서 정렬해주기 (삽입정렬 이용)

#include <stdio.h>

void Shell_Sort(int list[], int len, int interval){
    int i,j,k,temp;
    for(i=0;i<len;i++){
        if(i+interval >=len) break;
        for(j=i+interval;j<len ;j=j+interval){
            temp =list[j];
            
            for(k=j-interval; (k>=0)&&temp<list[k];k=k-interval){
                int temp2 = list[j]; // j가  반복을 돌며 바뀌기에 temp2를 선언해줘서 새롭게 변수도 바꿔줘야된다.
                list[j] =list[k];
                list[k] = temp2;
                
            }
           
        }
        
    }
       
}
    


void Shell_Sort_Start(int list[], int len, int interval){
    int i =0;
    while(interval>=1){
        printf(" %d\n ",interval);
        Shell_Sort(list,len,interval);
        for(i=0;i<len;i++){
            printf(" %d ",list[i]);
        } 
        printf(" \n");
        interval = interval/2;
    }
}





int main(void) {   // 1  2  3   4   5  6  7   8
    int list_a[8] = {51,125,23,142,12,36,124,235};
    Shell_Sort_Start(list_a,8,4);
}
