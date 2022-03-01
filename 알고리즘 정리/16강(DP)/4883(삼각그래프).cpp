#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[100010][3];
int arr[100010][3];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int idx = 0;
    for(;;){
        cin >> n;
        idx++;
        if(n==0) return 0;

        for(int i=0; i< n; i++){
            for(int j=0; j<3; j++){
                cin >> arr[i][j];
            }
        }

        int temp = arr[0][1] + arr[0][2];
        DP[1][0] = arr[0][1] + arr[1][0];
        DP[1][1] = min({arr[0][1], DP[1][0], temp})+ arr[1][1];
        DP[1][2] = min({arr[0][1], DP[1][1], temp})+ arr[1][2];
        // cout << "i : " << 0 << ", " << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << "\n";
        // cout << "i : " << 1 << ", " << DP[1][0] << " " << DP[1][1] << " " << DP[1][2] << "\n";
        for(int i=2; i< n; i++){
            DP[i][0] = min(DP[i-1][0], DP[i-1][1]) + arr[i][0];
            DP[i][1] = min({DP[i-1][0], DP[i-1][1], DP[i-1][2], DP[i][0]}) + arr[i][1];
            DP[i][2] = min({DP[i-1][1], DP[i-1][2], DP[i][1]}) + arr[i][2];

            // cout << "i : " << i << ", " << DP[i][0] << " " << DP[i][1] << " " << DP[i][2] << "\n";
        }

        cout << idx <<". " << DP[n-1][1] << "\n";
    }

    

}