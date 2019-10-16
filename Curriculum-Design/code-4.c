#include <stdio.h>
#include <string.h>

//基因编码
int a_judge(char *s, int n){
    for (char *p = s; p < n + s; p++) {
        if(*p == '0')
            continue;
        return 0;
    }
    return 1;
}//判断是否为A编码

int b_judge(char s[], int n){
    for (char *p = s; p < n + s; p++)  {
        if(*p == '1')
            continue;
        return 0;
    }
    return 1;
}//判断是否为B编码

int recur(char *p,char *s){

    char s1[5] = {""}, s2[5] = {""};
    char *q = p;
    unsigned int len = strlen(s);

    if(a_judge(s,len))
        strcat(p, "A");
    else if (b_judge(s,len))
        strcat(p, "B");
    else{
        strcat(p, "C");

        strncpy(s1, s, len/2);
        recur(q,s1);
        //取前段s1进行递归
        strncat(s2, s + len/2, len/2);
        recur(q,s2);
        //取后段s2进行递归
    }
}//递归函数


int main() {
    char s0[9] = {"01001011"};

    char result[14] = {0};

    recur(result, s0);

    puts(result);

    return 0;
}