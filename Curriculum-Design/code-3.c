#include <stdio.h>

//密码是一个C进制的数,并且只能由给定的M个数字中的某些构成,
//密码不超过500位，同时密码是一个给定十进制整数N的正整数倍,
//0≤N≤5000, 1≤M≤16 , 2≤C≤16

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std ;
int N, M, C, T;
int letter[20];
bool vis[5001];

struct node{
    int a;
    int b[505];
    int num;
    int step;
};

bool bfs(){
    queue<node>q;
    node head, tail;
    memset(vis, false, sizeof(vis));
    head.a = 0;
    head.num = 0;
    head.step = 0;
    q.push(head);

    while(!q.empty()){
        head = q.front();
        q.pop();
        for(int i = 0; i < M; i ++){
            tail.a = head.a * C + letter[i];
            if(!tail.a)
                continue;
            tail.step = head.step + 1;
            tail.num = head.num +1;
            tail.a = tail.a % N;
            if(vis[tail.a] || tail.num > 500)
                continue;
            vis[tail.a] = true;
            for(int j = 0; j < head.num; j ++){
                tail.b[j] = head.b[j];
            }
            tail.b[head.num] = letter[i];
            if(!tail.a){
                for(int j = 0; j < tail.num; j ++){
                    if(tail.b[j] > 9)
                        printf("%c", tail.b[j] + 'A' - 10);
                    else
                        printf("%d", tail.b[j]);
                }
                printf("\n");
                return true;
            }
            q.push(tail);
        }
    }
    return false;
}

int main(void){
    char c;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d%d", &N, &C, &M);
        for(int i = 0; i < M; i ++){
            getchar();
            scanf("%c", &c);
            if(c >= 'A' && c <= 'F')
                letter[i] = c - 55;
            else
                letter[i] = c - '0';
        }
        sort(letter,letter + M);
        if(!N){
            if(!letter[0])
                printf("0\n");
            else
                printf("give me the bomb please\n");
            continue;
        }

        if(!bfs())
            printf("give me the bomb please\n");
    }
    return 0;
}



