// -------------------------------------------------------
// 问:桌上有个能盛得下五个水果的空盘子。爸爸不停地向盘子中放苹果或者橘子，
// 儿子不停的从盘中取桔子享用，女儿不停的从盘中取苹果享用。
// 规定三人不能同时从盘中取放水果。试用信号量实现爸爸、儿子和女儿这三个循环进程之间的同步。
// -------------------------------------------------------
// 解析：生产者---消费者问题的变形，
// 相当于一个能生产两种产品的生产者（爸爸）向两个消费者（儿子和女儿）提供产品的同步问题，
// 需要设置两个不同的full信号量apple和orange，初值为0，另外需要一个empty同步信号量，初始值为5，
// 一个对于盘子互斥访问的信号量mutex，初始值为1。
// -------------------------------------------------------

#define N 5 
typedef int semaphore

semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

// Father进程
While(TRUE){
    P(empty);
    P(mutex);
    put_apple_or_orange();
    if(fruit==apple)
        V(apple);
    else
        V(orange);
    V(mutex);
}

// Daughter进程
While(TRUE)
{
    P(apple);
    P(mutex);
    Fetch_apple();
    V(mutex);
    V(empty);
}

// Son进程
While(TRUE)
{
    P(orange);
    P(mutex);
    Fetch_orange();
    V(mutex);
    V(empty);
}

