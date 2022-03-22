#include <stdio.h>

int FF[1000];

int init() {
    for (int i=2; i <1000; i++)
        FF[i] = -1;
    FF[0] = FF[1] = 1;
}

int F(int n){
    if(FF[n] != -1) 
        return FF[n];
    FF[n] = F(n-2) + F(n-1);
    return FF[n];
}

int main(){
    init();
    printf("%d", F(5));
}

