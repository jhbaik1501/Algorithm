#include <iostream>
#include <algorithm>

using namespace std;
int T, n;
int arr[1000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        long long ans =0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int max_val = -1;
        for(int i=n-1; i>=0; i--){
            if(max_val < arr[i]){
                max_val = arr[i];    
            }
            ans += max_val - arr[i];
        }
        cout << ans << "\n";
    }
}