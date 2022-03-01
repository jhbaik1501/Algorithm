#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;



int n;

int main(){

    int T;
    cin >> T;
    while(T--){
        int DP[10001] = {0, };
        int N, M;
        int coin[21];
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> coin[i];
            DP[coin[i]] = 1;
        }
        cin >> M;

        DP[0] = 1;
        for(int i= 0; i<= M; i++){
            for(int j=0; j<N; j++){
                if(i-coin[j] > 0){
                    DP[i] = DP[i-coin[j]] * DP[coin[j]];
                    cout << "DP[" << i << "] : " << DP[i] << "\n";
                }
            }

        }
        cout << DP[M] << "\n";
    }
}