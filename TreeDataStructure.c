// Tree Data Structure.

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeRoot {
    int data;
    struct TreeRoot *left;
    struct TreeRoot *right;
}TreeRoot;

TreeRoot* InsertRoot(int data,TreeRoot *right, TreeRoot* left){
    TreeRoot *C;
    C =(TreeRoot*)malloc(sizeof(TreeRoot));
    C-> data = data;
    C->left = left;
    C->right = right;
    return C;
    
    
}
// Data 크기에 따른 자동 자리잡기 함수
TreeRoot* InsertNew(TreeRoot *C, int data){
    TreeRoot *temp;
    TreeRoot *temp2;
    temp = C;
    temp2 = temp;
    int i=100;
    while(1){
        if(temp==NULL){
            TreeRoot *new = (TreeRoot*)malloc(sizeof(TreeRoot));
            new->data = data;
            new->right = NULL;
            new->left = NULL;
            if (i==0){
                temp2->left = new;
            }
            else { temp2->right = new;}
            return new;
        }
        
        if(temp->data >data){
            temp2 = temp;
            temp = temp->left;
            i = 0;
        }
        else{
            temp2 = temp;
            temp = temp->right;
            i =1; 
        }
    }
}
//Data 에 해당하는 tree 노드 찾기
TreeRoot* FindData(TreeRoot *root, int data){
    TreeRoot *temp;
    temp = root;
    while(1){
        if(temp == NULL){
            printf("존재하지 않는 데이터입니다.");
            return NULL;
        }
        else if(temp->data == data){
            return temp;
        }
        else if(temp->data >data){
            temp = temp->left;
        }
        else {temp = temp->right;}
    }
}
//Data 에 해당하는 tree 노 7  8  9  10  11  12  13 드의 아버지 노드 찾기
TreeRoot* FindData_F(TreeRoot* root, int data){
    TreeRoot *temp, *temp2;
    temp = root;\
    temp2 = temp;
    while(1){
        if(temp == NULL){
            printf("존재하지 않는 데이터입니다.");
            return NULL;
        }
        else if(temp->data == data){
            return temp2;
        }
        else if(temp->data >data){
            temp2 = temp;
            temp = temp->left;
        }
        else {temp2 = temp; 
            temp = temp->right;}
    }
}

// Data에 해당하는 tree 노드 삭제하기
TreeRoot* DeleteData(TreeRoot *root,int data){
    TreeRoot *temp, *succ;
    TreeRoot *temp2;
    temp = FindData(root,data);
    if(temp->right==NULL && temp->left ==NULL){
        temp2 = FindData_F(root,data);
        //직접 아버지 노드에따른 자식노드들 연결해줘야되넹 왜이렇지 그냥 자식노드를 free()+NULL 로 포인터 초기화 안되나?
        if(temp2->right == temp){
            temp2->right = NULL; 
        }
        else{
            temp2->left =NULL;
        }
        free(temp);
        temp =NULL;
        return root;
    }
    else if(temp->right==NULL || temp->left ==NULL){
        if(temp->right ==NULL){
            temp2= FindData_F(root,data);
            temp2->left = temp->left;
            free(temp);
            return root;
        }
        else{temp2=FindData_F(root,data); temp2->right = temp->right;
        free(temp);temp = NULL;;
        return root;}
    }
    else{
        temp2= FindData_F(root,data);
        succ = temp->left;
        while(succ!=NULL){
            temp2 = succ;
            succ = succ->right;
        }
        if(succ == temp->right){
            temp->data = succ->data;
            temp->right = succ->left;
            free(succ); succ=NULL;
            return root;
        }
        else {
            temp->data = succ->data;
            temp2->right = succ->left;
            free(succ);succ=NULL;
            return root;
        }
    }

}
    





// DLR 데이터 반환 순서 선위 순회 연산
void printf_Root_FRIST(TreeRoot *root){
    if(root !=NULL){
        printf(" %d ", root->data);
        printf_Root_FRIST(root->left);
        printf_Root_FRIST(root->right);
    }
}


// LDR 데이터 반환 순서 중위 순회 연산
void printf_Root_MIDDLE(TreeRoot *root){
    if(root !=NULL){
        printf_Root_MIDDLE(root->left);
        printf(" %d ", root->data);
        printf_Root_MIDDLE(root->right);
    }
}



// LRD 데이터 반환 순서 후위순회 연산
void printf_Root_LAST(TreeRoot *root){
    if(root !=NULL){
        printf_Root_LAST(root->left);
        printf_Root_LAST(root->right);
        printf(" %d ", root->data);
    }
}

int main(void) {
    TreeRoot *A;
    TreeRoot *B;
    TreeRoot *C;
    TreeRoot *D;
    TreeRoot *E;
    TreeRoot *F;
    TreeRoot *first_root; 
    
    A= InsertRoot(7,NULL,NULL);
    B= InsertRoot(6,NULL,NULL);
    C= InsertRoot(5,NULL,NULL);
    D= InsertRoot(4,NULL,NULL);

    E= InsertRoot(3,A,B);
    F= InsertRoot(2,C,D);
    first_root= InsertRoot(1,E,F);
    printf_Root_FRIST(first_root);
    printf("\n");
    printf_Root_MIDDLE(first_root);
    printf("\n");
    printf_Root_LAST(first_root);

    printf_Root_MIDDLE(first_root);

    TreeRoot*Second_root;

    Second_root = (TreeRoot*)malloc(sizeof(TreeRoot));
    Second_root = InsertRoot(10,NULL,NULL);

   
    printf("\n");
    A= InsertNew(Second_root,11);
    B= InsertNew(Second_root,9);
    C= InsertNew(Second_root,12);
    D= InsertNew(Second_root,8);
    E= InsertNew(Second_root,13);
    F= InsertNew(Second_root,7);
    printf_Root_MIDDLE(Second_root);
    Second_root = DeleteData(Second_root,13);
    printf("\n");
    printf_Root_MIDDLE(Second_root);
    
    first_root= FindData(Second_root,15);// 존재하지 않는 데이터입니다.
    first_root= FindData(Second_root,9);
    printf("\n%d",first_root->data);
    first_root = FindData_F(Second_root,7);
    printf("\n%d",first_root->data);
}
