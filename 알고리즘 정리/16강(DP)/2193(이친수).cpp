#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

long long DP[1002];
int N;
int main(){
    cin >> N;
    DP[1] = 1;
    DP[2] = 1;

    for(int i=3; i<N+1; i++){
        
        DP[i] = DP[i-1] + DP[i-2];
        
        
    }
    cout << DP[N] ;
}