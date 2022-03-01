#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int coin[110];
int DP[10010];
int main(){
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coin[i]; 
    }

    DP[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            DP[j] = DP[j] + DP[j-coin[i]];
        }
    }

    cout << DP[k];
}