#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int N;
int arr[100010];
int ans1, ans2;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int i=0, j= N-1;
    sort(arr,arr+N);
    int num = 0x7fffffff;
    while(i < j){ //같아져도 안댐.
        if(abs(num) > abs(arr[i] + arr[j]) ){
            num = arr[i] + arr[j];
            ans1 = arr[i];
            ans2 = arr[j];
        }

        if(arr[i] + arr[j] < 0){
            i++;
        }
        else if(arr[i] + arr[j] > 0){
            j--;
        }
        else{
            ans1 = arr[i];
            ans2 = arr[j];
            break;
        }
        // cout << i << ", " << j << ", " << num << "\n";
    }

    cout << ans1 << " " << ans2;
}
    
