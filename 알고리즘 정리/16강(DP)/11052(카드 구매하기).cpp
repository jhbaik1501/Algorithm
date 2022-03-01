#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int DP[1001];
int arr[10005];
int main(){
    cin >> N;
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1; i<N+1; i++){
        cin >> DP[i];
    }

    for(int i=1; i<N+1; i++){
        for(int j=0; j<i; j++){
            DP[i] = max(DP[i-j] + DP[j], DP[i]);
        }
    }

    cout << DP[N];
}