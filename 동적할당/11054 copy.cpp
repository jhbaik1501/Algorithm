#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[2][1002];
int value[1002];
int N;




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i= 1; i < N+1; i++){
        cin >> value[i];
    }

    DP[0][1] = 1;
    for(int i = 2; i < N+1; i++){
        DP[0][i] = 1;
        for(int j = i; j >0; j--){
            if(value[j] < value[i]){
                DP[0][i] = max(DP[0][j]+1, DP[0][i]) ;
            }
        }
        
        for(int j = i; j >0; j--){
            if(value[j] > value[i]){
                DP[1][i] = max({DP[0][j] +1, DP[1][j] +1, DP[1][i]});
            }
        }

        cout << value[i] << ": "<<DP[0][i] << ", "<<DP[1][i] << "\n";
    }

    int idx = 1;
    for(int i=1; i <N+1; i++){
        idx = max({idx, DP[0][i], DP[1][i]});
    }

    cout << idx;
}

/*
13
10 20 10 30 20 50 2 3 4 5 6 7 8
*/