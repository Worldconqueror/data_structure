#include <stdio.h>

void Select_Sort(int list[], int size){
    int i, k ,temp;
    
    for(i=0; i<size-1; i++){
        for(k=i+1; k<size; k++){
            if(list[i]>list[k]){
                temp = list[i];
                list[i] = list[k];
                list[k] = temp;
            }
        }
    }
    
    for(i=0;i<size; i++){
        printf(" %d ",list[i]);
    }
}


int main(){
    int list[6] = {12,2,42,52,22,32};
    Select_Sort(list,6);
}
