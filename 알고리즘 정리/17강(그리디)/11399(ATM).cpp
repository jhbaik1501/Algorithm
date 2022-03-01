#include <iostream>
#include <algorithm>

using namespace std;


int N;
int arr[1001];
int main() {
    
    cin >> N;
    for(int i=0; i <N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);
    int ans = arr[0];
    for(int i=1; i <N; i++){
        arr[i] += arr[i-1];
        
        ans += arr[i];
    }
    cout << ans;
}