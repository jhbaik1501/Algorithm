/* 에라토스테네스의 체 이용 */
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    
    for (int i =0; i<N; i++){
        cin >> arr[i];
    }
    int max_num = 0;
    int target;
    sort(arr, arr + N);
    for (int i =0; i < N; i++){
        for (int j =0; j < N; j++){
            for (int k = 0; k < N ; k++){
                target = arr[i] + arr[j] + arr[k];
                if(upper_bound(arr, arr+N,target) - lower_bound(arr, arr+N, target) >= 1){
                    max_num = max(target, max_num);
                }
            }
        }
    }

    cout << max_num;

}