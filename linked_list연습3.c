#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* Making_List(Node* C, int data){
    Node* new =(Node*)malloc(sizeof(Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    if(C== NULL){
        C = new;
        return C;
    }
    Node* temp =C;
    while(temp->right!=NULL){
        temp = temp->right;
        
        
    }
    temp->right = new;
    new->left = temp;
    return C;
    
}


void Printf_List(Node* C){
    Node* temp = C;
    printf("\n");
    while(temp->right!=NULL){
        printf(" %d ",temp->data);
        temp = temp->right;
    }
    printf(" %d ",temp->data);
}


Node* Insert_First(Node*C, int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    Node* temp =C;
    temp->left = new;
    new->right = temp;
    C= new;
    return C;
}

int Search_data(Node* C,int data){
    int i =0;
    Node* temp = C;
    
    while(temp!=NULL){
        i++;
        if(temp->data == data){
            
            return i;
        }
        temp = temp->right;
    }
    
    return 0;
}

Node* Delete_data(Node* C,int data){
    int number = Search_data(C,data);
    if(number==0){printf("\n존재하지 않는 데이터입니다."); return C;}
    
    if(number==1){
        Node* temp =C;
        if(temp->right ==NULL){
            free(temp);
            return C;
        }
        C = temp->right;
        free(temp);
        return C;
    }
    
    Node* temp;
    Node* temp2;
    temp =C;
    temp2 = C;
    int i;
    for(i=0;i<number-1;i++){
        temp2 = temp;
        temp = temp->right;
    }
    if(temp->right == NULL){
        temp2->right =NULL;
        return C;
    }
    
    temp2->right = temp->right;
    temp->right->left = temp2;
    free(temp);
    temp =NULL;
    
    return C;
    
}



int main(void){
    Node* C;
    C= NULL;
    C=Making_List(C,6);
    C=Making_List(C,5);
    C=Making_List(C,4);
    C=Making_List(C,3);
    C=Making_List(C,2);
    Printf_List(C);
    printf("\n");
    C= Insert_First(C, 7);
    Printf_List(C);
    int number = Search_data(C,4);
    C= Delete_data(C,2);
    Printf_List(C);
    C =Delete_data(C,7);
    Printf_List(C);
}
