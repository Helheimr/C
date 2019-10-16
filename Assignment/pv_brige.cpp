// 问:请用信号量解决过独木桥问题：同一方向的行人可以同时过桥；
// 当某一方向有人过桥时，另一个方向的行人必须等待；当某一方向无人过桥时，
// 另一个方向的行人可以过桥。
// 解析：是读者—写者问题的变形，同一个方向的人可以同时过桥相当于读者可以同时读。
// 可将两个方向的行人看做两类不同的读者，同类读者可以同时读（过桥），不同类读者必须互斥的读（过桥）。
// 首先需要设置两个记录两个不同方向过桥行人数量的变量countA和countB，初始化为0；
// mutexA和mutexB实现对两个变量的互斥访问，初始化为1，另一互斥信号量bridge实现对不同方向行人对桥的互斥共享。


typedef int semaphore

semaphore mutexA = 1;
semaphore mutexB = 1;
semaphore bridge = 1;

semaphore countA = 1;
semaphore countB = 1;


// A方向行人过桥
while(TRUE){
	P(mutexA);
	countA++;

	if (countA == 1)
		P(bridge);
	V(mutexA);
	gap_bridge();

	P(mutexA);
	countA--;
	if(countA == 0)
		V(bridge);
	V(mutexA);
}

// B方向行人过桥
while(TRUE){
	P(mutexB);
	countB++;

	if (countB == 1)
		P(bridge);
	V(mutexB);
	gap_bridge();

	P(mutexB);
	countB--;
	if(countB == 0)
		V(bridge);
	V(mutexB);
}
