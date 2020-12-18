// simple LINKED LIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode *link;
} listnode;

typedef struct {
    listnode *head;
} list_Head;

list_Head* createdList_linked(void){
    list_Head *L;
    L = (list_Head*)malloc(list_Head);
    L->head = NULL;
    return L;
}

void add_list(list_Head*L,int x) {
    listnode *new;
    new = (listnode*)malloc(listnode);
    new->data = int;
    new->link = L->head;
    L->head = new;
}

void print_list(list_Head*L){
    listnode *p;
    p = L->head;
    while(p->link != NULL){    
    printf('%d',p->data);
    p = p->link;
    }   
}

int main(void) {
    list_Head *L;
    L = createdList_linked();
    
    add_list(L,12);
    add_list(L,33);
    print_list();
}