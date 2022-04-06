#include <stdio.h>
#define Size 10
void InsertSort(int a[],int n)
{//折半查找
    int i,j,low,high,mid;
    for(i = 2;i < n;i++)
    {
        a[0] = a[i];
        high = i-1,low = 1;
        while (high >= low)
        {//开始折半查找
            mid = (high + low)/2;
            if(a[i] > mid) high = mid -1;  //查找左子表
            else low = mid +1;      //查找右子表,循环结束的时候high就是待放置的位置
        }
        for(j = i-1;j >= high + 1;j-- ) a[j+1] = a[j];
        a[high+1] = a[0];
        
    }


}

void ShellSort(int a[],int n)
{
    int i,j,tmp;

    

}
int main()
{
    int a[Size] = {0,2,1,3,4,2,5,7,9,6};
    // InsertSort(a,Size);


    for(int i = 0;i<=Size;i++) printf("%d ",a[i]);
    return 0;
}