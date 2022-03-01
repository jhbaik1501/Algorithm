#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#define ll long long;
using namespace std;

long long DP[1001];

int n;

int main(){
    cin >> n;
    DP[1] = 1;
    DP[2] = 2;
    for (int i= 3; i < n+1; i++){
        DP[i] += DP[i-2];
        DP[i] += DP[i-1];
        DP[i] = DP[i] % 10007;
    }

    cout << DP[n] ;
}