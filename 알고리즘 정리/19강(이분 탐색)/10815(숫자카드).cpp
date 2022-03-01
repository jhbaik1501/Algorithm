#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int arr[500100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=0; i< N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    cin >> M;

    int temp;
    for(int i=0; i<M; i++){
        cin >> temp;
        
        cout << upper_bound(arr,arr+N, temp)- lower_bound(arr, arr+N, temp) << " ";
    }
}