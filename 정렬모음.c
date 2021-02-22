#include <stdio.h>
typedef int element;
//
void printf_list(int list[], int size){
    for(int i =0;i<size;i++){
        printf(" %d ",list[i]);
    }
}

// 선택 정렬
void select_sort(int list[],int size){
    // size = 배열길이
    int i,j;
    printf("정렬 시작전 배열:");
    for( i =0;i<size;i++){
        printf(" %d ",list[i]);
    }
    printf("\n");
    printf("정렬을 시작합니다.\n");
    for(i =0;i<size-1; i++){
        for(j =i+1;j<size;j++){
            int temp = list[i];
            if(list[j]<temp){
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    for(i =0; i<size;i++){
        printf(" %d ",list[i]);
    }
    printf("\n정렬을 완료합니다.\n");
}

// 버블 정렬

void bubble_sort(int list[],int size){
    int i,j;
    for(i =0;i<size-1;i++){
        int main =i;
        for(j =i+1;j<size;j++){
            int temp = list[i];
            if(temp>list[j]){
                list[i] = list[j];
                list[j] = temp;
                i++;
            }
            i= main;
        }
    }
    printf("정렬을 시작합니다\n");
    for(i=0;i<size;i++){
        printf(" %d ",list[i]);
    }
    printf("\n정렬을 완료합니다.\n");
}

// 퀵 정렬
int quick_sort_pivot(int list[],int start,int end){
    int L = start;
    int R = end;
    int pivot = (start+end)/2;
    while(L<R){
        while(L<R && list[L]<list[pivot]) L++;
        //L은 pivot 위치를 넘어서 못간다.
        while(L<R && list[R]>=list[pivot]) R--;
        // R 는 pivot 을 넘어서 갈수 있다.
        if(L<R){
            int temp =list[L];
            list[L] = list[R];
            list[R] = temp;
        }

        if(L==pivot){
                pivot = R;
            } 
        }
    //R =L 인상황
    int temp = list[pivot];
    list[pivot] = list[R];
    list[R] = temp;
    return R;
}
int quick_list_start(int list[],int start,int end){

    if(start<end){
        int p = quick_sort_pivot(list,start,end);
        quick_list_start(list,start,p-1);
        quick_list_start(list,p+1,end);
    }
    //밑에 숫자는 총 배열의 사이즈에 따라 달라진다. 사이즈 = 숫자;
    if(start+end+1 == 8){
        printf("정렬을 시작합니다.\n");
        printf_list(list,8);
        printf("\n정렬을 완료합니다.\n");
    }
}

//삽입 정렬
void insertion_sort(int list[],int size){
    int i, j;
    for(i=1;i<size;i++){
        int temp = list[i];
        j  = i;
        while(j>0 && list[j-1]>temp){
            int asp = list[j];
            list[j]  = list[j-1];
            list[j-1] = asp;
            j--;
        }
    }
    printf("정렬을 시작합니다.\n");
    printf_list(list,8);
    printf("\n정렬을 완료합니다\n");
   

    
}

    


int main(void){
    element list1[8] = {25,12,62,21,23,63,2,8};
    select_sort(list1,8);
    element list2[8] = {25,12,62,21,23,63,2,8};
    bubble_sort(list2,8);
    element list3[8] = {25,12,62,21,23,63,2,8};
    quick_list_start(list3,0,7);
    element list4[8] = {25,12,62,21,23,63,2,8};
    insertion_sort(list4,8);
}
