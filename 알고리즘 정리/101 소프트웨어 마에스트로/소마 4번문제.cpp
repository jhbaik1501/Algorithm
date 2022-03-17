#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int arr[8100];

int main(){
    
    cin >> N;

    for(int i=0; i< N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);
    
    int ans = 0;

    for(int i=0; i<N-2; i++){
        int left = i+1;
        int right = N-1;
        while(left < right){
            int sum = arr[i] + arr[left] + arr[right];
            if(sum <= 2500){
                cout << arr[i] << " " <<  arr[left] << " " <<  arr[right] << "\n";
                ans++;
                left++;
            }
            else{
                right--;
            }
        }

    }

    cout << ans;
}

/*
투 포인터
8000개 sort

2500칼로리 이하

4
400 500 800 1300

정답 : 3

*/