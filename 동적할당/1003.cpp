#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[2][42];
int N;




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    DP[0][0] = 1;
    DP[1][0] = 0;

    DP[0][1] = 0;
    DP[1][1] = 1;


    for (int i =2; i < 42; i++){
        DP[0][i] = DP[0][i-1] + DP[0][i-2];
        DP[1][i] = DP[1][i-1] + DP[1][i-2];
    }

    int idx;
    for (int i=0; i <N; i++){
        cin >>idx;
        cout << DP[0][idx] << " " << DP[1][idx] << "\n";
    }
}

/*
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6
*/