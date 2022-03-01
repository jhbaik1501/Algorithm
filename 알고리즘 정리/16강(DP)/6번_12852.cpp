#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int DP[1000000];
int pre[1000000];
int N, M;

int min(int a, int b){
    if (a > b) return b;
    else return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    DP[1] = 0;
    
    for(int i =2; i < N+1; i++){
        DP[i] = DP[i-1] +1;

        if(min(DP[i-1] +1, DP[i]) == DP[i-1] +1)
            pre[i] = i-1;

        if(i %2 == 0){
            DP[i] = min(DP[i/2] +1, DP[i]);

            if(min(DP[i/2] +1, DP[i]) == DP[i/2] +1)
                pre[i] = i/2;
        }
        if(i %3 == 0){
            DP[i] = min(DP[i/3] +1, DP[i]);

            if(min(DP[i/3] +1, DP[i]) == DP[i/3] +1)
                pre[i] = i/3;
        }
    }

    cout << DP[N] << "\n";

    int cnt = N;
    while(cnt){
        cout << cnt << " "; 
        cnt = pre[cnt];
    }
    
    
}