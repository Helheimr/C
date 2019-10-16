#include<stdio.h>
#include<string.h>
#include<ctype.h>

void squeeze(char s[],int c) {
    int i,j;
    for (i = 0, j = 0; s[i] != '\0'; i++){
        if (s[i] != c){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';	//字符串的结束标记
}//删除字符串中某个字符

char upchar(char *s){
    char *p;
    for(p = s; *p != '\0'; p++){
        if(*p > 'a' && *p < 'z')
            *p -= 32;
    }
}//转换大小写

int main(){

    char s_put[100];
    int k=2;

    printf("\n"
           "Enter the string key S, containing only letters, numbers, and '-':\n");
    gets(s_put);


    printf("\n" "Given a number K:");
    scanf("%d",&k);

    squeeze(s_put,'-');
    int len = strlen(s_put);
    int m = (len % k == 0)? len/k-1: len/k;
    //m 为 重组s字符串 所需 '-' 数目

    char s_new[m+len+1];

    for(int i = len+m-k-1; i > 0; i -= (k+1))
        s_new[i] = '-';
    //填充'-'

    int i, j;
    for(i = 0, j = 0; i < len; i++){
        if (s_new[j] == '-')
            j++;
        s_new[j++] = s_put[i];
    }
    s_new[j++] = '\0';
    //填充其他空间

    char *p_new = s_new;
    upchar(p_new);
    //转换大小写

    printf("\n"
           "Reformat the string:\n");
    puts(p_new);
}