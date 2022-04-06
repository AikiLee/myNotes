#include <stdio.h>

typedef struct {
    int data;
}test;


// void swap_1(int a,int b)
// {//传值，直接修改地址中的值
//     int temp ;
//     temp = a;
//     b = a;
//     a = temp;
// } 

// void swap_2(int *a,int *b)
// {//交换地址，却无用，只是暂时
//     int * tmp;
//     tmp = a;
//     b = a;
//     a = tmp;
// }

void swap(test  t1)
{
    t1.data = 1;
}

int main()
{
//     int a,b;
//     a=1,b=2;
//     swap_1(a,b);
//     printf("a,b:%d %d\n",a,b);
//     swap_1(&a,&b);
//     printf("a,b:%d %d\n",a,b);

    test t;
    swap(t);
    printf("%d ",t.data);


    return 0;
}