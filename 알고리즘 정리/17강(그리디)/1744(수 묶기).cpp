#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[51];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int minus =0, plus = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] <= 0){
            minus++;
        }
        else{
            plus++;
        }
    }
    sort(arr, arr+n);

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    int ans = 0;
    // cout << minus  << " : minus \n";
    if(minus % 2 == 0){ // 마이너스가 짝수인경우.
        for(int i=0; i<minus; i+= 2){
            ans += arr[i] * arr[i+1];
        }
    }
    else{
        if(minus != 1){
            for(int i=0; i<minus-2; i+= 2){
                ans += arr[i] * arr[i+1];
            }
        }
        ans += arr[minus-1];
    }

    // cout << ans << " Hi\n";
    if(plus % 2 == 0){ // 시작점이 끝.
        for(int i= n-1; i >= minus; i -= 2){
            if(arr[ i - 1 ] == 1){
                ans += 1 + arr[ i ];
            }
            else{
                ans += arr[ i ] * arr[ i - 1 ];
            }
        }
    }
    else{
        if(plus != 1)
            for(int i= n-1 ; i >= minus+2; i -= 2){
                if(arr[ i - 1 ] == 1){
                    ans += 1 + arr[ i ];
                }
                else{
                    // cout << "HI" ;
                    ans += arr[ i ] * arr[ i - 1 ];
                }
            }
        ans += arr[ minus ];
    }
    
    cout << ans;
}