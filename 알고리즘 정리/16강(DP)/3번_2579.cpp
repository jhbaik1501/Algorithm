#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int DP[2][302];
int N;


int max(int a, int b){
    if (a >= b){
        return a;
    }
    else return b;
}



int main(){
    cin >> N;
    
    int idx;
    for (int i= 0; i < N-1; i++){
        cin >> idx;
        if(i== 0){
            DP[0][0] = idx;
            DP[1][0] = idx;
        }
        else if(i== 1){
            DP[0][1] = idx + DP[1][0];
            DP[1][1] = idx;
        }
        else{
            DP[0][i] = idx + DP[1][i-1];
            DP[1][i] = max(idx + DP[0][i-2], idx + DP[1][i-2]);
        }
        
    }

    cin >> idx;

    cout << max(idx + DP[1][N-2], max(DP[0][N-3] + idx, DP[1][N-3] + idx));
}