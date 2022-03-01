#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;

int arr[1001];
vector<int> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    

    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            v.push_back(arr[i]+arr[j]);
        }
    }
    
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin(), v.end());
    int ans =0;
    int t = v.size();
    
    for(int i=0; i<N; i++){
        for(int j=i; j< N; j++){
            if(binary_search(v.begin(), v.end(), arr[j] - arr[i])){
                ans = max(arr[j], ans);
            }
        }
    }

    cout << ans;
}