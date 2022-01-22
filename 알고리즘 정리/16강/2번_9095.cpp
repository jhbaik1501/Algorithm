#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int DP[12];
int T;
int main(){
    DP[1] = 1; // 1
    DP[2] = 2; // 1+1 , 2
    DP[3] = 4; // 1+1+1, 2+1, 3, 1+2
    for(int i=4; i < 12; i++){
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    } 
    int idx;
    cin >> T;
    for(int i =0; i < T; i++){
        cin >> idx;
        cout << DP[idx] << "\n";
    }
}