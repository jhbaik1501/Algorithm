#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

long long DP[101][101];
long long DP2[101][101];
int main(){
    int n, m;
    cin >> n >> m;
    DP[1][0] = 1; DP[1][1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<= m; j++){
            if(j == 0) DP[i][j] = 1;
            else DP[i][j] = DP[i-1][j] + DP[i-1][j-1];

            if(DP[i][j] >= 10000000000000000){
                DP2[i][j] += DP[i][j] / 10000000000000000;
                DP[i][j] %= 10000000000000000;
            }
        }
    }
    if(DP2[n][m] != 0)
        cout << DP2[n][m] << DP[n][m];
        
}