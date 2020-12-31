#include <stdio.h>

void Select_Sort(int list[], int size){
    int i, k ,temp;
    
    for(i=0; i<size-1; i++){
        printf(" %d번째 ",i);
        for(k=i+1; k<size; k++){
            if(list[i]>list[k]){
                temp = list[i];
                list[i] = list[k];
                list[k] = temp;
            }
        }
        int l =0;
        for(l=0;l<size; l++){
            printf(" %d",list[l]);
        }
        printf("\n");
    }
    
}

void Bubble_Sort(int list[], int size){
    int i,k,temp;
    
    for(i=0;i<size;i++){
        printf(" %d번째",i);
        for(k=0;k<size-1-i;k++){
            temp = list[k];
            if(temp>list[k+1]){
                list[k]= list[k+1];
                list[k+1] = temp;
            }
        }
        int l =0;
        for(l=0;l<size; l++){
            printf(" %d",list[l]);
        }
        
        printf("\n");
    }
}
// a와 b는 배열의 인덱스 값이 된다.(0과 마지막 부분)

int Quick_Sort(int list[], int a,int b){
    
    int L = a;
    int R = b;
    int quick = (a+b)/2;
    int i =0;
    while(L<R){
        while((R>L)&&(list[L]<list[quick])) L++;
        while((R>L)&&(list[R]>=list[quick])) R--;
        
        if(L<R){
            int temp = list[L];
            list[L]=list[R];
            list[R] = temp;
        
            if(L==quick) quick =R;
        }

        
    }
    
    int temp2 = list[R];
    list[R] = list[quick];
    list[quick] = temp2;
    printf("\n");
    return R;
}
void Quick_Printf(int list[],int a,int b){
    int p;
    if(a<b){
        p = Quick_Sort(list,a,b);
        Quick_Printf(list,a,p-1);
        Quick_Printf(list,p+1,b);
    }
    
}
void print_array(int list[], int size){
    int i =0;
    for(i=0;i<size;i++){
        printf(" %d ",list[i]);
        
    }
}


int main(){
    int list[6] = {123,242,415,231,921,237};
    Select_Sort(list,6);
    int list_a[6] = {123,242,415,231,921,237};
    Bubble_Sort(list_a,6);
    int list_b[6] = {123,242,415,231,921,237};
    Quick_Sort(list_b,0,5);
    Quick_Printf(list_b,0,5);
    print_array(list_b,6);
    
}
