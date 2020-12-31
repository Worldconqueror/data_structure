// 퀵 정렬

#include <stdio.h>

int Quick_Sort(int list[], int start, int last){

    int quick = (start+last)/2; // quick = start 해도 가능, quick = last 해도 가능

    int L = start;
    int R = last;

    while(L<R){
        while((L<R)&&(list[L]<list[quick])) L++;
        while((L<R)&&(list[R]>=list[quick])) R--;

        if(L<R){
            int temp =list[L];
            list[L] = list[R];
            list[R] = temp;

            if(L==quick) quick = R;
        }
    }
    // L=R 인 상황  // 가지도 오지도 못하는 그상황 -> 그자리 == 인덱스 quick의 원소 자리임!
    int temp2 = list[R];
    list[R] = list[quick];
    list[quick] = temp2;
    return R; // 고정된 자리 리턴
}

void Quick_start(int list[], int start, int last){
    int p;
    int L =start;
    int R = last;
    if(start<last){
        p= Quick_Sort(list,L,R);
        Quick_start(list,L,p-1);
        Quick_start(list,p+1,R);
    }
}







int main(void){

    int list_a[5] = {12,42,32,52,22};
    Quick_Sort(list_a,0, 4);
    Quick_start(list_a,0,4);
    int i =0;

    for(i=0;i<5;i++){
        printf(" %d ",list_a[i]);
    }
}
