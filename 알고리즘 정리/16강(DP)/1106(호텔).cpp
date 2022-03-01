#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[1010];
int C, N;
pair<int,int> arr[21];
int main(){
    ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    
    cin >> C >> N;
    fill(&DP[0], &DP[1010], 0x7fffffff);
    // cout << N;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a,b};
    } // 대는 비용, 고객의 수

    for(int i=0; i<N; i++){

        int val = arr[i].first;
        for(int j=1; j<= C; j++){
            // cout << "val : " << val << ", "<< DP[j]<< "\n";
            // cout << " arr.second : "<<arr[i].second << "// ";
            if(arr[i].second >= j) DP[j] = min( val , DP[ j ] );
            else DP[j] = min( DP[ j - arr[i].second ] + val, DP[ j ]);

            // cout << DP[j] << " ";
        }
        // cout << "\n";
    }

    cout << DP[C];
}