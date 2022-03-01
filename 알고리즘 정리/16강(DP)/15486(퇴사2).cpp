#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[1500010];
int Ti[1500010];
int Pi[1500010];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i=1; i<= N; i++){
        int a, b;
        cin >> a >> b;
        Ti[i] = a;
        Pi[i] = b;
    }

    for(int i=1; i<= N+1; i++){
        int temp = 0;
        for(int j=0; j< Ti[i]; j++){
            
            temp = max( DP[ i + j ], temp );
            DP[ i + j ] = temp;
        }
        
        if(i + Ti[i] <= N+1)
            DP[ i + Ti[i] ] = max(DP[ i + Ti[i]], DP[i] + Pi[i]);

    }

    cout << DP[N+1];
}