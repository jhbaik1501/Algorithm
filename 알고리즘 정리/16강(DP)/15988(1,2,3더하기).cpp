#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

long long DP[1000020];

int T, n;

int main(){
    cin >> T;

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for(int i=4; i<= 1000000; i++){
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
        DP[i] %= 1000000009;
    }
    while(T--){
        cin >> n;
        cout << DP[n] << "\n";
    }
}