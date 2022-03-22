#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int DP[1002];
int value[1002];
int N;

int max(int a1, int a2){
    if (a1 >= a2) return a1;
    else return a2;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i= 1; i < N+1; i++){
        cin >> value[i];
    }

    DP[1] = 1;
    for(int i = 2; i < N+1; i++){
        DP[i] = 1;
        for(int j = i; j >0; j--){
            if(value[j] < value[i]){
                DP[i] = max(DP[j]+1, DP[i]) ;
                //cout << i << "," <<DP[i] << "\n";
            }
        }
        
    }

    int idx = 1;
    for(int i=1; i <N+1; i++){
        idx = max(idx, DP[i]);
    }

    cout << idx;
}

/*
13
10 20 10 30 20 50 2 3 4 5 6 7 8
*/