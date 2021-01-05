#include <stdio.h>
#include <stdlib.h>
#define MAX 8 //리스트 원소 갯수 적기
// 퀵정렬 -> 순차원소 검색

int Quick_Array(int list[],int start, int end){
    int L, R;
    L = start;
    R = end;

    int quick = (L+R)/2;

    while(L<R){
        while((L<R)&&list[L]<list[quick]) L++;
        while((L<R)&&list[quick]<=list[R]) R--;

        if(L<R){
            int temp;
            temp = list[R];
            list[R] = list[L];
            list[L]= temp;
            
            if(L==quick){
                quick = R;
            }
        }
    }
    
    
    // 나머지는 L=R인 경우이다.
    int temp = list[R];
    list[R] = list[quick];
    list[quick] = temp;
        
    return R;
}
void Printf_array(int list[]){
    int i;
    
    for(i=0;i<MAX;i++){
        printf(" %d ",list[i]);
    }
    printf("\n");
}

void Quick_Repeat(int list[],int start, int end){
    int i,j;
    i = start;
    j= end;
    if(i<j){
        int mid = Quick_Array(list,i,j); //
        
        Quick_Repeat(list,i,mid-1);
     
        Quick_Repeat(list,mid+1,j);
        
    }
}


//퀵정렬한 것에 대해 순차검색 사용하기
void Simple_Searching(int list[],int number,int key){
    int i=0;
    while(i<number){
        if(list[i]==key){
            printf("검색하신 원소가 리스트의 %d번째에 위치합니다.",i+1);
            return;
        }
        i++;
    }
    printf("검색하신 원소가 존재하지않습니다.");
    return;
    
}

// 퀵정렬 한것에 대한 이진검색
int i =0;


void Binary_Searching(int list[],int start, int number,int key){
    int last = number-1;
    int mid = (start+last)/2;
    if(i>=MAX){
        printf("%d번째 시도, 원소를 찾지 못찾지못했습니다",i);
        return;
    }
    
    if((list[MAX-1]<key)||(list[0]>key)){
        i++;
        printf("%d번째 시도, 원소를 찾지못했습니다.",i);
        return;
    }
    
    if(start==number){
        if(list[start]==key){
            i++;
            printf("%d번째만에 발견했습니다.",i);
            return;
        }
        printf("%d번째 시도, 발견하지 못했습니다.");
    }
        
    
    if(list[mid]==key){
        i++;
        printf(" %d번째만에 발견되었습니다.", i);
        return;
    }
    
    else if(list[mid]>key){
        i++;
        last = mid-1;
    }
    
    else if(list[mid]<key){
        i++;
        start = mid+1;
    }
    
    Binary_Searching(list,start,last,key);
}



int main(void){
    int list_a[MAX];
    int i =0;
    for(i=0;i<MAX;i++){
        list_a[i] = rand();
    }
    Printf_array(list_a);
    Quick_Repeat(list_a,0,7);
    Printf_array(list_a);
    Simple_Searching(list_a,MAX,1957747793);
    printf("\n");
    Binary_Searching(list_a,0,MAX,1681692777);
}

