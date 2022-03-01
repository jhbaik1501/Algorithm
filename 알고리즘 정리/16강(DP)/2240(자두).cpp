#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;



int T, W;
int DP[1001][31][2];
int arr[1001];
int main(){

    cin >> T >> W;

    for(int i=0; i<T; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<W+1; i++){ // 움직이는 횟수
        
        if(i == 0){
            for(int j=0; j<T; j++){
                if(arr[j] == 1){
                    DP[j][i][0] = DP[j-1][i][0] + 1; 
                }
                else{
                    DP[j][i][0] = DP[j-1][i][0]; 
                }

                // cout << DP[j][i][0] << ", " << DP[j][i][1] << "\n";
            }

            
        }
        else{

            // cout << "i = " << i << "\n";
            for(int j=0; j<T; j++){ // 시간
                
                if(j < i-1){
                    DP[j][i][0] = DP[j][i-1][0];
                    DP[j][i][1] = DP[j][i-1][1];
                }
                else{
                    if(arr[j] == 1){
                        DP[j][i][0] = max(DP[j-1][i][0], DP[j-1][i-1][1]) + 1;
                        DP[j][i][1] = max(DP[j-1][i][1], DP[j-1][i-1][0]); 
                    }
                    else{
                        DP[j][i][0] = max(DP[j-1][i][0], DP[j-1][i-1][1]);
                        DP[j][i][1] = max(DP[j-1][i][1], DP[j-1][i-1][0]) + 1; 
                    }
                }

                // cout << DP[j][i][0] << ", " << DP[j][i][1] << "\n";
            }
        }


    }

    cout << max(DP[T-1][W][0], DP[T-1][W][1]);
}