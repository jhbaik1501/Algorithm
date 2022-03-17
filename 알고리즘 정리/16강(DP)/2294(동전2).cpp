#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stdio.h>

using namespace std;

int n, k;
int arr[150];
int DP[10100] ;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&DP[1], &DP[10099], 0x7f7f7f7f);
    string str;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i < n; i++){
        for(int j = arr[i]; j<=k; j++){
            DP[j] = min( DP[j-arr[i]] + 1, DP[j]);
        }
        // for(int i=1; i<=k; i++)
        //     cout << DP[i] << " ";
        // cout << "\n";
    }
    if(DP[k] == 0x7f7f7f7f){
        cout << -1;
    }
    else cout << DP[k];
    // for(int i=1; i<=k; i++)
    //     cout << DP[i] << " ";
    
}
