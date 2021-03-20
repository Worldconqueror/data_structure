#include <stdio.h>



void shell_sort(int list[], int size){

    int i,j,k;
    for(i=1; i<size;i++){
        int temp = list[i];
        k = i;
        for(j=i-1;j>=0;j--){
            if(temp<list[j]){
                list[k] = list[j];
                list[j] = temp;
                k=j;
            }
        }
        printf(" %d 단계: ",i);
        for(int ii=0;ii<size;ii++){
            printf(" %d ",list[ii]);
        }
        printf("\n");
        
    }
    
}





int main(void){
    int list1[9]= {69,10,30,2,16,8,31,22};
    for(int a= 0; a<8; a++){
        printf(" %d ",list1[a]);
    }
    printf("\n");
    shell_sort(list1,8);
}
