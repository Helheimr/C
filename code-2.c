#include <stdio.h>
#define N 4

int FK(int *p, int k){
    int *p_arr[N];
    int s = 0;

    for (int i = 0; i < N; i++) {
        p_arr[i] = p + (i + k) % N;
    }

    for (int j = 0; j < N; j++) {
        s += *p_arr[j] * j;
    }
    return s;
}

int max_array(int const s[], int n){
    int max = s[0];
    for (int i = 1; i < n; ++i) {
        max = max > s[i]? max: s[i];
    }
    return max;
}


int main() {
    int array[N] = {4,3,2,6};
    int *p = array;
    int F_array[N];
    int max;

    printf("Print Your Array A(N = %d):\n",N);
    /*for(int i = 0; i < N; i++)
        scanf("%d",array[i]);*/

    for (int i = 0; i < N; ++i) {
        F_array[i] = FK(p,i);
    }

    printf("\nThe max of F(0), F(1), ..., F(n-1) is %d \n",max_array(F_array,N));
    return 0;
}