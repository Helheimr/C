#include<stdio.h>
#include<stdlib.h>

int n,s;
//法雷数列

void pre(int a,int b,int c,int d){//利用二分法输出法雷数列
    if(b+d>n) return ;
    pre(a,b,a+c,b+d);//a+c 分子 b+d 分母
    printf("%d/%d,",a+c,b+d);
    pre(a+c,b+d,c,d);
}

// Farey Sequence 的构造
//法雷数列的构造可采用2分法，即如果 a/b， c/d （a/b <c/d）是一个n级法雷数列中的两个元素，
// 且b+d <=n,  则可以在a/b, c/d 中间插入一个分数 (a+b)/(c+d)。下面以5级法雷数列为例，给出详细的过程。
//
//step1: 准备两个数 0/1, 1/1 作为整个法雷数列的第一个元素和最后一个元素
//　　0/1, 1/1
//step2: 在两个数中间插入1个数1/2, 变为
//　　0/1, 1/2, 1/1
//step3: 在每对相邻两个数中间插入1个数，变为
//　　0/1, 1/3, 1/2, 2/3, 1/1
//step4: 在每对相邻两个数中间插入1个数，变为
//　　0/1, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 1/1
//step5: 0/1 和 1/4 之间 和3/4和 1/1 仍然可插入1个数，使得插入的数分母不大于5
//　　0/1, 1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5, 1/1
//至此，该序列包含了所有分母不大于5的最简真分数，且各个分数以递增顺序排列。

int eular(int n){
    double sum=n;
    int i;
    for(i=2;i<=n;i++){
        if(n%i==0){
            sum*=(1-1.0/i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    return (int)sum;
}//利用欧拉函数求与n互素的数的个数


int SUM(int n){
    int j,sum=0;
    for(j=2;j<=n;j++)
        sum+=eular(j);
    return sum;
}//欧拉函数求和


int main ()
{
    scanf("%d",&n);
    printf("0/1,");
    pre(0,1,1,1);
    printf("1/1\n");
    s=SUM(n);
    printf("%d", s+2);

    return 0;
}