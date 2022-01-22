#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int DP[1000000];
int N;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    DP[1] = 1;
    DP[2] = 2;
    for(int i =3; i < N+1; i++){
        DP[i] = DP[i-1] + DP[i-2];
        DP[i] = DP[i] %15746;
    }

    cout << DP[N] << "\n";
    
    
}