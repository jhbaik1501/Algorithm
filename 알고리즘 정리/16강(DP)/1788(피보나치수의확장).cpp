#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int DP[1000010];

int n;

int main(){
    cin >> n;
    DP[0] = 0;
    DP[1] = 1;
    if(n >=0){
        for(int i=2; i <= n; i++){
            DP[i] = DP[i-1] + DP[i-2];
            DP[i] %= 1000000000;
        }
    }
    else{
        DP[1] = 1;
        DP[2] = -1;
        for(int i= 3; i <= abs(n); i++){
            DP[i] = DP[i-2] - DP[i-1];
            if(DP[i] > 0){
                DP[i] %= 1000000000;
            }
            else if(DP[i] < 0){
                DP[i] = -(abs(DP[i]) % 1000000000);
            }
            
        }
    }

    if(DP[abs(n)] > 0){
        cout << "1\n";
        cout << DP[abs(n)];    
    }
    else if(DP[abs(n)] == 0){
        cout << "0\n";
        cout << DP[abs(n)];
    }
    else{
        cout << "-1\n";
        cout << abs(DP[abs(n)]);
    }

    

}