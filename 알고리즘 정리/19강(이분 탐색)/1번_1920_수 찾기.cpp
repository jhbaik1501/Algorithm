/* 에라토스테네스의 체 이용 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int mylower_bound(int * arr1, int * arr2, int key){
    int size = arr2 - arr1;
    
    int st = 0;
    int en = size-1 ;
    int mid;
    while(en >= st){
        mid = (st + en) / 2;
        if(key > arr1[mid]){
            st = mid + 1;
        }
        else if(key == arr1[mid]){
            en = mid;
            return 1;
        }
        else{
            en = mid -1;
        }
        // if(key == 5)
        //     cout << "st, en : "<< st <<", "<< en;
    }

    return 0;
}

int N, M;
int arr[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    cin >> M;
    int temp;
    for(int i=0; i<M; i++){
        cin >> temp;
        cout << mylower_bound(arr, arr+N, temp) << " ";
    }

}