#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[45][3];
int arr[45];
int N, M;
vector<int> v;
int main(){
    cin >> N >> M;

    int temp;
    for(int i=0; i<M; i++){
        cin >> temp;
        arr[temp] = -1;
    }
    for(int i=1; i<N+1; i++){
        
        if(i+1 > N || arr[i+1] == -1){
            v.push_back(DP[i-1][0] + DP[i-1][1])
        }
        else if(i-1 < 0 || arr[i-1] == -1){
            DP[i][0] = 1;
            DP[i][1] = 1;
        }
        else{
            DP[i][0] = DP[i-1][0] + DP[i-1][2];
            DP[i][1] = DP[i-1][0] + DP[i-1][2];
            DP[i][2] = DP[i-1][1] + DP[i-1][2];
        }

    }
}