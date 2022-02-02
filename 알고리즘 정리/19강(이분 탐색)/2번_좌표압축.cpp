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

int arr[1000000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    vector<int> temp;
    
    for(int i =0; i< N; i++){
        cin >> arr[i];
        temp.push_back(arr[i]);
    }

    sort(temp.begin(), temp.end());

    vector<int> uniq;
    for(int i =0; i< N; i++){
        if(i == 0 || temp[i-1] != temp[i])
            uniq.push_back(temp[i]);
    }

    for(int i=0; i <N; i++){
        cout << lower_bound(uniq.begin(), uniq.end(), arr[i]) - uniq.begin() << " ";
    }


}