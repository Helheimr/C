#include <stdio.h>
#include <math.h>
/*
 * 给一个长度为 的字符数组和一个长度为k的01数组req，根据要求编写折叠加密和解密的算法。
 */

int row_array(int n,char (*arr)[n]){
    int row = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i][0] != '0')
            row++;
        else
            break;
    }
    return row;
}//返回 数组的有效 行数

int col_array(int n,char (*arr)[n]){
    int col = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[0][i] != '0')
            col++;
        else
            break;
    }
    return col;
}//返回 数组的有效 行数

void encrypted(int k,int n,int const reg[],char (*str_array)[n]){

    int row,col;//row 行数 col 列数
    char temp;

    for (int i = 0; i < k; ++i) {
        row = row_array(n,str_array);
        col = col_array(n,str_array);
        switch (reg[i]){
            case 0:{
                for (int m = 0; m < row; m++)
                    for (int j = 0; j < col / 2; ++j) {
                        str_array[row+m][j] = str_array[m][col/2+j];
                        str_array[m][col/2+j] = '0';
                    }//存不动的部分

                //row 行数 col 列数

                for (int m = 0; m < (col==2?row/2:row); m++)
                    for (int j = 0; j < col / 4.0; ++j) {
                        temp = str_array[m][j];
                        str_array[m][j] = str_array[row-1-m][col/2-j-1];
                        str_array[row-m-1][col/2-j-1] = temp;
                    }//存旋转的部分
                break; }
            case 1:{
                for (int m = 0; m < row; m++)
                    for (int j = 0; j < col / 2; ++j) {
                        str_array[row+m][j] = str_array[m][j];
                        str_array[m][j] = '0';
                    }//存不动的部分

                //row 行数 col 列数

                for (int m = 0; m < row; m++)
                    for (int j = 0; j < col / 2; ++j) {
                        str_array[m][j] = str_array[row-1-m][col-1-j];
                        str_array[row-1-m][col-1-j] = '0';
                    }//存旋转的部分
                break;}
            default:break;
        }
    }
    //加密过程
}//折叠加密函数

void notes(int k,int n,int const reg[],char (*str_array)[n]){
    //printf("----------------------------------\n\n");
    printf("-----The Primitive Sequence-------\n");

    for (int i1 = 0; i1 < n; ++i1) {
        for (int i = 0; i < n; ++i) {
            if (str_array[i1][i]!='0')
                printf("%c",str_array[i1][i]);
            else
                printf(" ");
        }
        if (str_array[i1+1][0]!='0')
            printf("\n");
    }

    printf("---------The REG Sequence---------\n");
    for (int i = 0; i < k; ++i) {
        printf("%d ",reg[i]);
    }
    printf("\n-------The Folding sequence-------\n");
}//提示内容

void print_arr(int n,char (*str_array)[n]){
    for (int i1 = 0; i1 < n; ++i1) {
        for (int i = 0; i < n; ++i) {
            if (str_array[i1][i]!='0')
                printf("%c",str_array[i1][i]);
            else
                printf(" ");
        }
        if (str_array[i1+1][0]!='0')
            printf("\n");
    }
}//输出 二维数组

int main() {
    int k=3;
    //printf("Enter your K value:\n");
    //scanf("%d",&k);

    int reg[k];
    int n = (int)pow(2,k);

    char str_array[n][n];   //二维数组储存数据

    printf("Enter your 2**%d array(Input 0 end:)\n",k);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            str_array[j][i] = '0';
        }
    }//二维数组 清零

    for (int l = 0; l < n; ++l) {
        gets(str_array[l]);
        if (str_array[l][0]== '0')
            break;
    }//输入 二维数组

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if ((str_array[j][i] >= 'a' && str_array[j][i] <= 'z') || (str_array[j][i] >= 'A' && str_array[j][i] <= 'Z'))
                continue;
            else
                str_array[j][i] = '0';
        }
    }//格式化 字符串

    printf("Enter Reg[]:\n");
    for (int i = 0; i < k; ++i) {
        scanf("%d",&reg[i]);
    }//输入reg的值

    notes(k,n,reg,str_array);//提示信息

    encrypted(k,n,reg,str_array);//给定参数 折叠

    print_arr(n,str_array);//输出折叠后的结果

    return 0;
}