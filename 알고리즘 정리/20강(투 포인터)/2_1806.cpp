/* 에라토스테네스의 체 이용 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, S;
int arr[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for(int i=0; i<N;i++){
        cin >> arr[i];
    }

    int st = 0, en=0;
    int sum = 0;
    int num = 1;
    int ans = 0x7fffffff;
    for(int st =0; st<N; st++){
        if(st != 0){
            sum -= arr[st-1];
            num--;
        }
        while(en< N && sum + arr[en] < S){
            sum += arr[en];
            en++;
            num++;
        }
        if(en >= N) break;
        ans = min(num, ans);
    }
    if(S == 0){
        cout << "1";
    }
    else if(ans == 0x7fffffff){
        cout << "0";
    }
    else
        cout << ans;
}