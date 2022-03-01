#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100010];

bool compare(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N, compare);
    int ans =0;
    for(int i=0; i< N-2; i=i+3){
        
        ans += arr[i+1] + arr[i];
    }
    if(N % 3 == 1){
        ans += arr[N-1];
    }
    else if(N % 3 == 2){
        ans += arr[N-1] + arr[N-2];
    }

    cout << ans;
}