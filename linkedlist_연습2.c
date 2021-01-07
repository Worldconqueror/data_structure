#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}Node;




Node* Making_Node(Node* C, int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->link = NULL;

    if(C==NULL){
        C = new;
        new->link = C;
        return C;
    }
    
    Node* temp;
    temp =C;
    
    while(temp->link!=C){
        temp = temp->link;
    }
    temp->link = new;
    new->link =C;
    return C;
}

int Searching_Data(Node* C, int data){
    if(C==NULL){
        printf("노드가 존재하지 않습니다.");
        return 0;
    }

    int i=0;
    
    Node* temp;
    temp = C;
    while(temp->link!=C){
        i++; 
        if(temp->data == data){
            printf("\n노드를 찾았습니다.");
            printf("\n %d번째 노드에 존재합니다.\n",i);
            return i;
        }
        
        temp = temp->link;
    }
    if(temp->data ==data){printf("마지막 노드에 해당 데이터가 존재합니다.");
        return 0;
    }
    printf("노드가 존재하지않습니다.");
    return 0;
    
}



Node* Delete_Node(Node* C,int data){
    int number = Searching_Data(C,data);
    if(number==0){
        printf("존재하지 않는 데이터입니다");
        return C;
    }
    
    if(number==1){
        Node* temp;
        temp =C;
        C = temp->link;
        free(temp);
        temp =NULL;
        return C;
    }
    
    int i;
    Node* temp = C;
    Node* temp_mom = temp;
    for(i=1;i<number;i++){
        temp_mom = temp;
        temp = temp->link;
    }
    if(temp->link !=NULL){
        temp_mom->link =temp->link;
    }
    else{temp_mom->link = NULL;}
    free(temp);
    temp =NULL;
    printf("데이터의 노드를 삭제했습니다.");
    return C;
}

void Number_Insert(Node* C, int data, int data2){
    Node* temp = C;
    int number = Searching_Data(C,data);
    int i;
    for(i=1;i<number;i++){
        temp = temp->link;
    }
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data2;
    Node* temp2 = temp->link;
    new->link = temp2;
    temp->link = new;
    return;
}

void Pritnf_list(Node* C){
    Node* temp;
    temp = C;
    while(temp->link!=C){
        printf(" %d ",temp->data);
        temp = temp->link;
    }
    printf(" %d ",temp->data);
}







int main(void){
    Node* C = (Node*)malloc(sizeof(Node));
    C = NULL;
    C= Making_Node(C,11);
    C= Making_Node(C,12);
    C= Making_Node(C,13);
    C= Making_Node(C,14);
    C= Making_Node(C,15);
    C= Making_Node(C,17);
    C= Making_Node(C,18);
    C= Making_Node(C,19);
    Pritnf_list(C);
    Number_Insert(C,15,16);
    Pritnf_list(C);
    Delete_Node(C,19);
    Pritnf_list(C);
    Searching_Data(C,20);
    Searching_Data(C,19);
    
}
