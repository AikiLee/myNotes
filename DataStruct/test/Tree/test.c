#include <stdio.h>
    void swap1(int *p,int *q){
        int * temp = p;
        p = q;
        q = temp;
    }
int main(void){
    int p = 2;
    int q = 3;

    swap1(&p,&q);
    printf("p:%d , q:%d",p,q);
    return 0;
}