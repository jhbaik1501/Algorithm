#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;

int L;
int arr[51];
int n;
int main() { 
    cin >> L;
    int k= L;
    int idx=0;
    
    while(L--){
        cin >> arr[idx++];
    }
    cin >> n;
    sort(arr, arr+k);

    int num = 0;
    int a, b;
    while(true){
        // cout << "arr[num] : " << arr[num] << "\n";
        
        if(n < arr[num]) {
            
            if(num -1 >= 0)
                a = arr[num-1];
            else a= 0;
            b = arr[num];
            break;
        }
        else if(n == arr[num]){
            cout << 0;
            return 0;
        }
        num++;
    }

    // a + 1 부터 
    // b - 1
    // 까지
    // cout << "a :" << a << "b : " << b;
    // a + 1 이 n과 같다면 거기까지하고 그만
    int ans =0;
    for(int i= n; i>= a+1; i--){
        ans += b-n;
        // cout << "ans : "<< ans << "\n";
    }
    cout << ans-1;
}



