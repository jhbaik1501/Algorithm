#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int arr[1005];
int DP[1005];
int main(){
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        DP[i] = arr[i];
    }

    for(int i=0; i<N; i++){
        for(int j=i-1; j>= 0; j--){
            if(arr[i] > arr[j]){
                DP[i] = max(DP[i], DP[j] + arr[i]);
            }
        }
        // cout << DP[i] << " ";
    }
    cout << *max_element(DP, DP+N);
}