#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[101][100020] = {0x7fffffff,};
pair<int, int> arr[111];
int N, M;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&DP[0][0], &DP[100][100020], 0x7fffffff);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        
        int a,b;
        cin >> a >> b;
        
        arr[i] = {a,b};
    }

    sort(arr+1, arr+N+1, compare);
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            if(j <= arr[i].first){
                // cout << "HI~"<< arr[i].first;
                DP[i][j] = min(DP[i-1][j], arr[i].second);
            }
            else{
                if(DP[i-1][j-arr[i].first] == 0x7fffffff){
                    continue;
                }
                else{
                    DP[i][j] = min( DP[i-1][ j-arr[i].first] + arr[i].second, DP[i-1][j]);
                }
            }

            //cout << DP[i][j] << " "; 
        }
        //cout << "\n";
    }

    cout << DP[N][M];
}