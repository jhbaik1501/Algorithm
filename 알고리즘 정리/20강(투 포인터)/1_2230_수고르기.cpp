/* 에라토스테네스의 체 이용 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for(int i=0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    int st=0, en =0;
    int ans = 0x7fffffff;
    while(true){
        if(en >= N || st >= N-1) break;
        
        if(M <= arr[en] - arr[st]){
            ans = min(ans, arr[en] - arr[st]);
            st++;
        }
        else{ 
            en++;
        }

    }
    cout << ans;
}