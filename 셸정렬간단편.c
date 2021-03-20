#include <stdio.h>



void insert_sort(int list[], int size){
    int middle = size/2;
    int i, j,temp,num;
    num = 0;
    i =0;
    int a;
    while(middle!=0){

        for(i=0;i<size-middle;i++){
            temp =list[i];
            for(j=i+middle;j<size;j=j+middle){
                if(list[i]>list[j]){
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
        
        num++;
        printf("%d 번째 실행",num);
        for(int k=0;k<size;k++){
            printf(" %d ",list[k]);
        }
        printf("\n");
        middle = middle/2;
        
        if(middle ==1){
            for(i=0;i<size-1;i++){
                for(j=i;j<size;j++){

                    if(list[i]>list[j]){
                        temp = list[i];
                        list[i] = list[j];
                        list[j]=temp;
                    }
                }
            }
        }

    }
   
}





int main(void){
    int list1[8]={69,10,30,2,16,8,31,22};
    insert_sort(list1,8);
}
