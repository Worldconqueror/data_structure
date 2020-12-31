#include <stdio.h>
#define MAX 100

int array[MAX];

void Divide_Sort(int link[], int m, int mid, int n){
    int t;
    int i =m;
    int j = mid +1;
    int k = m; // array 시작 인덱스;
    while((i<=j)&&(j<=n)){
        if(link[i]>=link[j]){
            array[k] = link[j];
            j++; 
        }
        else{ array[k]= link[i]; i++; }
    
        k++;
    }

    
    
    if(i>mid)for(t=j;t<=n;t++,k++) array[k] = link[t];
        

    else for(t=i;t<=mid; t++,k++) array[k] = link[t];
    
    for(t=m;t<=n;t++) link[t] = array[t];
    for(t=0;t<8; t++) printf(" %d ",link[t]);
    printf("\n");
    
}



void mergeSort(int link[],int m, int n){
    int middle;
    if(m<n){
        middle = (m+n)/2;
        mergeSort(link,m,middle);
        mergeSort(link,middle+1,n);
        Divide_Sort(link,m,middle,n);
    }
}


int main(void) {
    int link[8] ={69,10,30,2,16,8,31,22};
    mergeSort(link,0,7);
    
}
