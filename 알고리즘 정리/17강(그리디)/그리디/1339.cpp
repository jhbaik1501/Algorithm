#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int arr[45];

int compare(int a, int b){
    return a> b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    string temp;
    for (int i=0; i<N; i++){
        cin >> temp;
        for (int j =0; j < temp.size(); j++){
            arr[temp[j] - 'A'] += pow(10, temp.size() -j - 1);
            //cout << arr[temp[j] - 'A'] << " " << temp[j] - 'A' << "\n";
        }
        temp = "";
    }

    // for(int i = 0; i < 46; i++){
    //     cout << arr[i] << " ";
    // }
    
    sort(arr, arr+45, compare);
    int answer = 0;
    for(int i = 9; i >= 0; i--){
        answer += arr[9-i] * i;
    }
    cout << answer;
}