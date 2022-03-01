#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int N;
int arr[1001];
pair<int,int> DP[1001];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        DP[i].first = 1;
        DP[i].second = -1;
    }

    pair<int,int> ans;
    int pos;
    for(int i=0; i<N; i++){
        
        for(int j=i-1; j>=0 ;j--){
            if(arr[i] > arr[j]){
                if(max(DP[i].first , DP[j].first + 1) == DP[j].first + 1){
                    DP[i].first = max(DP[i].first , DP[j].first + 1);
                    DP[i].second = j;
                }
            }
        }

        if(ans.first < DP[i].first){
            ans = DP[i];
            // cout << "DP[" << i << "].second" << DP[i].second << " ";
            pos = i;
        }
    }

    stack<int> tmp;
    cout << ans.first << "\n";
    tmp.push(arr[pos]);
    // cout << arr[pos] << " ";
    while(ans.second != -1){
        tmp.push(arr[ans.second]);
        // cout << arr[ans.second] << " ";
        ans.second = DP[ans.second].second;
    }   
    while(!tmp.empty()){
        cout << tmp.top() << " ";
        tmp.pop();
    }
}