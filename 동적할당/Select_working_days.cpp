#include <stdio.h>

int max(int a1, int a2){
    if(a1 > a2)
        return a1;
    else
        return a2;
}

int W(int a[], int n) //여기서는 0이 일을 안하는 경우로. n은 배열의 크기.
{
    int** D = new int*[n+1];
    for (int i =0; i< n+1; i++){
        D[i] = new int[2];
    }
     D[1][0] = 0; D[1][1] = a[1];
    for(int i =2; i <=n; i++){
        D[i][0] = max(D[i-1][0], D[i-1][1]);
        D[i][1] = D[i-1][0] + a[i];
    }
    return max(D[n][0], D[n][1]);
}

int main(){
    int n = 8;
    int* k = new int[n]{5,3,7,2,6,8,4,9};
    printf("work : %d", W(k, n));
}