//그냥 안 밟은것을 기준으로 생각한다.
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int DP[302];
int N;


int min(int a, int b){
    if (a <= b){
        return a;
    }
    else return b;
}



int main(){
    cin >> N;
    int sum = 0;
    int idx;
    for (int i= 0; i < N-1; i++){
        cin >> idx;
        if(i == 0 || i == 1 || i ==2)
            DP[i] = idx;
        else{
            DP[i] = min(DP[i-2] + idx, DP[i-3]+ idx);
        }
        sum += idx;
    }

    cin >> idx;
    if( N <= 2){
        cout << idx;
    }
    else{
        cout << sum - min(DP[N-3], DP[N-4]);
    }
}