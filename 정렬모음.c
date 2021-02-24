#include <stdio.h>
#include <stdlib.h>
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

// 셸 정렬
void shell_sort(int list[], int size){
    int standard = size/2;
    int h = standard;
    int start = 0;
    while(h!=0){
        for(int i =0;i<size-h;i++){
            if(list[start]>list[start+h]){
                int a = list[start];
                list[start] = list[start+h];
                list[start+h] =a;
            }
            start++;
        }
        h--;
        start = 0;
    }

    printf("정렬을 시작합니다\n");
    for(int j=0;j<size;j++){
        printf(" %d ",list[j]);
    }
    printf("\n정렬을 완료합니다.\n");
}

// 병합 정렬
void Merge_Ready_Sort(int list[],int start,int end){
    int middle = (start+end)/2;
    int i = start;
    int j = middle+1;
    int t;
    int k= start;
    int sort[end+1]; // sort 설정이유-> 값바꿈으로 리스트를바꾸면 그자체에서 값들이바뀌기때문이다.
    while(i<=middle && j<=end){
        if(list[i]<=list[j]){
            sort[k] = list[i];
            i++;
        }
        else{
            sort[k] =list[j];
            j++;
        }
        k++;
    }
    
    if(i>middle) for(t=j;t<=end;t++,k++) sort[k] = list[t];
    else for(t=i;t<=middle;t++,k++) sort[k] = list[t];
    
    for(t=start;t<=end;t++) list[t] = sort[t];
    
    
    printf("\n");
    for(int p=start;p<=end;p++){
        printf(" %d ",list[p]);
    }
    printf("\n");
}

void Merge_Done_Sort(int list[],int start,int end){
    int mid = (start+end)/2;
    if(start<end){
        Merge_Done_Sort(list,start,mid);
        Merge_Done_Sort(list,mid+1,end);
        Merge_Ready_Sort(list,start,end);
    }
}

// 기수 정렬
void Radix_Sort(int list[],int size){
    typedef struct Node{
        int data;
        struct Node* link;
    }Node;
    
    typedef struct {
        Node*front;
        Node* reaf;
    }queue;
    
    queue* Making_queue(){
        queue* C = (queue*)malloc(sizeof(queue));
        C->reaf= NULL;
        C->front = NULL;
        return C;
    }
    
    void plus_node(queue* C,int data){
        if(C->front==NULL){
            Node* new = (Node*)malloc(sizeof(Node));
            new->data = data;
            new->link = NULL;
            C->front = new;
            C->reaf = new;
            
            return;
        }
        Node* new = (Node*)malloc(sizeof(Node));
        new->data = data;
        new->link = NULL;
        new->link = C->reaf;
        C->reaf = new;
        return;
    }
    int delete_node(queue*C){
        if(C->front==NULL){
            return 0;
        }
        Node* new;
        new = C->reaf;
        if(new == C->front){
            int alpha = new->data;
            free(new);
            C->front =NULL;
            C->reaf = NULL;
            return alpha;
        }
        while(new->link!=C->front){
            new = new->link;
        }
        Node* temp = new->link;
        C->front = new;
        new->link = NULL;
        int data = temp->data;
        free(temp);
        temp=NULL;
        return data;
    }
    
    int standard= 10;
    queue* list_queue[10];
    int a =0;
    int z = 10;
    for(int p =0;p<10;p++){
        list_queue[p] = Making_queue();
    }
    int p = 0;
    
    for(a=0;a<size;a++){
        int k =list[a] % 10;
        plus_node(list_queue[k],list[a]);
    }
    queue* temp =list_queue[0];
    while(temp!=NULL)
    for(a=0;a<size;a++){
        printf(" %d ",list[a]);
    }
    
    
}



int main(void){ 
    element list1[8] = {25,12,62,21,23,63,2,8};
    printf("\nSLECT SORT\n");
    select_sort(list1,8); 
    element list2[8] = {25,12,62,21,23,63,2,8};
    printf("\nBUBBLE SORT\n");
    bubble_sort(list2,8);
    element list3[8] = {25,12,62,21,23,63,2,8};
    printf("\nQUICK SORT\n");
    quick_list_start(list3,0,7);
    element list4[8] = {25,12,62,21,23,63,2,8};
    printf("\nINSERTION SORT\n");
    insertion_sort(list4,8);
    element list5[8] = {25,12,62,21,23,63,2,8};
    printf("\nSHELL SORT\n");
    shell_sort(list5,8);
    element list6[8] = {69,10,30,2,16,8,31,22};
    printf("\nMERGE SORT\n");
    Merge_Done_Sort(list6,0,7);
    element list7[8] = {25,12,62,21,23,63,2,8};
    printf("\nMERGE SORT\n");
    Radix_Sort(list7,8);
}
