#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int arr[101][101];
long long DP[101][101];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=0; i< N; i++){
        for(int j=0; j< N; j++){
            cin >> arr[i][j];
        }
    }
    DP[0][0] = 1;
    for(int i=0; i< N; i++){
        for(int j=0; j< N; j++){
            
            // cout << DP[i][j] << " ";

            if(arr[i][j] == 0) continue;
            if(i+arr[i][j] < N){
                
                DP[i+arr[i][j]][j] += DP[i][j];
            }

            if(j+arr[i][j] < N){
                
                DP[i][j+arr[i][j]] += DP[i][j];
            }

            
        }
        // cout << "\n";
    }

    cout << DP[N-1][N-1];

}