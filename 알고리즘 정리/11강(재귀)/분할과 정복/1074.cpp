#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;


int N;
int R, C;

int recursive(int N, int r, int c){

    if(N == 0){
        return 0;
    }

    int temp = N/2;
    temp = temp*temp;
    cout << N << "," <<temp << "\n";
    if(r < N/2 && c < N/2)
        return recursive(N/2, r, c) + 0;
    if(r < N/2 && c >= N/2)
        return recursive(N/2, r, c - N/2) + temp;
    if(r >= N/2 && c < N/2)
        return recursive(N/2, r - N/2, c) + 2*temp;
    if(r >= N/2 && c >= N/2)
        return recursive(N/2, r - N/2, c - N/2) + 3*temp;
    
}


int main(){
    cin >> N;
    cin >> R >> C;
    int k = pow(2, N);
    //cout << k;
    cout << recursive(k, R, C);


}

