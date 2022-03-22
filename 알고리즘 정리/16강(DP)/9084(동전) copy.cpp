#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int T;
int N, M;

long long DP[10010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    while(T--){
        int coin[21];
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> coin[i];
        }
        cin >> M;
        fill(DP, DP+10010, 0);
        DP[0] = 1;
        for(int i=0; i<N; i++){
            for(int j = coin[i]; j <= M; j++){
                DP[j] = DP[j - coin[i]] + DP[j];
            }
        }

        cout << DP[M] << "\n";
    }
}