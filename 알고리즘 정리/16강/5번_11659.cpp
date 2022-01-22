#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int DP[100000];

int N, M;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int idx;
    for(int i =1; i < N+1; i++){
        cin >> idx;
        DP[i] = DP[i-1] + idx;
    
    }

    int a,b;
    for(int i =0; i< M; i++){
        cin >> a>> b;
        cout << DP[b] - DP[a-1]<< "\n";
    }
    
}