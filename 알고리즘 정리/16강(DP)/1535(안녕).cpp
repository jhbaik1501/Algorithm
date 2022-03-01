#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int DP[25][105];
pair<int,int> person[25];
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> N;

    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        person[i].first = temp;
    }

    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        person[i].second = temp;
    }

    for(int i=0; i<N; i++){
        for(int j= 0; j< 100; j++){
            
            if(i == 0){
                if ( j >= person[i].first )
                    DP[i][j] = person[i].second;
                continue;
            }

            if ( j < person[i].first )
            {
                DP[i][j] = DP[i-1][j];
            }
            else{
                DP[i][j] = max( DP[ i - 1 ][ j - person[i].first ] + person[i].second, DP[i-1][j]);
            }
            
            
        }
        // cout << "DP : " << DP[i][99] << "\n";
    }

    cout << DP[N-1][99];
}