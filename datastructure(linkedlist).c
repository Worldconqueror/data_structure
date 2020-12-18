#include <stdio.h>        //add Poly programming
#include <stdlib.h>
#define MAX 100
typedef struct {
    int degree;
    float coef[MAX];
} polynomial;
void printf_poly(polynomial);
polynomial addpoly(polynomial, polynomial);
polynomial get_poly();

polynomial addpoly(polynomial a,polynomial b) {
    
    polynomial C;
    int i = 0;
    int a_k = 0;
    int b_k = 0;
    int a_degree = a.degree;
    int b_degree = b.degree;


    if (a.degree > b.degree || a.degree==b.degree){
        C.degree = a.degree;
    }
    else {
        C.degree = b.degree;
    }
    
    for (i=0; i<=C.degree; i++) {

        if(a_degree > b_degree){
            C.coef[i] = a.coef[a_k];
            a_degree--;
            a_k++;
        }
        else if(a_degree == b_degree) {
            C.coef[i] = a.coef[a_k] + b.coef[b_k];
            a_degree--;
            b_degree--;
            a_k++; b_k++;
        }
        else if(b_degree>a_degree){
            C.coef[i] = b.coef[b_k];
            b_degree--;
            b_k++;
        }
        
    }

    return C;
    
}
void printf_poly(polynomial T){
    int i =0;
    int T_degree = T.degree;
    printf("written the Polynomial: ");
    for(i=0; i<=T.degree; i++){
        if (i==T.degree){
            printf("%f",T.coef[i]);
            break;
        }

        printf("%f^%d + ",T.coef[i],T_degree);
        T_degree--;
    }
}

polynomial get_poly(){
    int x, i=0;
    float input_num;
    polynomial T;
    
    printf("\nplz input Max degree of Polynimial : ");
    scanf("%d", &x);
    
    for(i=0; i<=x; i++){
        printf("plz put coef>> ");
        scanf("%f", &input_num);
        T.coef[i] = input_num;
    }
    T.degree = x;
    
    return T;
    
}

int main(void) {
    polynomial A = {4,{3,2,1,2,2}};
    polynomial B = {3,{2,4,0,1}};
    polynomial C;

    C = addpoly(A, B);
    printf_poly(C);    
    get_poly();
}