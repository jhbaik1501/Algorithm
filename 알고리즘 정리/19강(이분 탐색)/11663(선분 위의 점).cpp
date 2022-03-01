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

using namespace std;
int N, M;
int arr[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    while(M--){
        int a, b;
        cin >> a >> b;
        
        cout << upper_bound(arr, arr+N, b) - lower_bound(arr, arr+N, a) << "\n";
    }

}