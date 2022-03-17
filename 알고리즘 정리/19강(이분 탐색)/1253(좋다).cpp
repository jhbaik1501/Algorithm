#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int N;
int arr[2100];
int check[2100];
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    set<int> S;

    for(int i=0; i<N; i++){
        cin >> arr[i]; 
    }

    sort(arr, arr+N);
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int temp = arr[i] + arr[j];
            
            if(temp == arr[i]) continue;
            if(temp == arr[j]) continue;;
            if(S.find(temp) == S.end()){
                    
                // if(upper_bound(arr, arr+N, temp) - lower_bound(arr, arr+N, temp) > 0){
                //     cout << "temp : " << temp << "\n";
                // }
                ans += upper_bound(arr, arr+N, temp) - lower_bound(arr, arr+N, temp);    
                S.insert(temp);
            }
            
        }
    }

    cout << ans;
}