#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[1010][12];

int N;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        if(i == 0){
            for(int j=0; j<10; j++)
                DP[i][j] = 1;
        }
        else{
            for(int j=0; j<10; j++){
                for(int k=j; k>=0; k--){
                    DP[i][j] += DP[i-1][k];
                
                }
                
            }
        }
    }
    int ans = 0;
    for(int j=0; j<10; j++){
        ans += DP[N-1][j] ;
    }
    cout << ans %10007;
}