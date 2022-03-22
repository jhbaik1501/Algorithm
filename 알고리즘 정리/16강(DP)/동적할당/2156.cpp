#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int DP[3][10002];
int n;

int max(int a, int b){
    if (a >= b) return a;
    else return b;
}

int max(int a1, int a2, int a3){
    int ret = 0;
    int temp[4] = {a1, a2, a3};
    for (int i =0; i < 3; i++){
        if(ret <= temp[i]) ret = temp[i];
    }
    return ret;
}

int max(int a1, int a2, int a3, int a4){
    int ret = 0;
    int temp[4] = {a1, a2, a3, a4};
    for (int i =0; i < 4; i++){
        if(ret <= temp[i]) ret = temp[i];
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    cin >> n;

    int idx;
    for(int i=1; i < n+1; i++){

        cin >> idx;
        if(i == 1){
            DP[0][1] = idx; 
            DP[1][1] = idx;
            DP[2][1] = 0;
        }
        else if (i ==2){
            DP[0][2] = idx; 
            DP[1][2] = idx + DP[0][1];
            DP[2][2] = DP[0][1];
        }
        else{
            DP[0][i] = max(DP[0][i-2] +idx, DP[1][i-2] + idx, DP[2][i-1] +idx);
            DP[1][i] = DP[0][i-1] + idx;
            DP[2][i] = max(DP[0][i-1], DP[1][i-1], DP[2][i-1]);
        }
        cout << DP[0][i] << ","<< DP[1][i] << "," << DP[2][i] << "\n";
    }


    cout << max(DP[0][n], DP[1][n], DP[2][n]);
    
}