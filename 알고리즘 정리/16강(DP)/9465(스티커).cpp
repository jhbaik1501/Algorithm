#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[100020][2];
int arr[100020][2];
int T, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    
    while(T--){
        cin >> n;
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                cin >> arr[j][i];
            }
        }

        for(int i=0; i<n; i++){
            if(i==0){
                DP[i][0] = arr[i][0];
                DP[i][1] = arr[i][1];
            }
            else if(i==1){
                DP[i][0] = DP[i-1][1] + arr[i][0];
                DP[i][1] = DP[i-1][0] + arr[i][1];
            }
            else{
                DP[i][0] = max( {DP[i-1][1], DP[i-2][0], DP[i-2][1]} ) + arr[i][0];
                DP[i][1] = max( {DP[i-1][0], DP[i-2][0], DP[i-2][1]} ) + arr[i][1];
            }
        }
        int temp =  max(DP[n-1][0], DP[n-1][1]);
        cout << temp << "\n";
    }
}