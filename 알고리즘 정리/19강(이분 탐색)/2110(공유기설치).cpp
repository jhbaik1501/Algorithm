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
int N, C;
int home[200010];

int solve(int mid){
    int WIFI = 1;
    int tmp = home[0] + mid;
    while(tmp <= home[N-1]){

        if(upper_bound(home, home+N, tmp) - lower_bound(home, home+N, tmp) == 1){
            tmp = *lower_bound(home, home+N, tmp);
        }
        else{
            tmp = *upper_bound(home, home+N, tmp);
        }

        tmp += mid;
        WIFI++;
    }
    
    // cout << "WIFI : " << WIFI-- << "\n";
    return WIFI;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> C;

    for(int i=0; i<N; i++){
        cin >> home[i];
    }

    sort(home, home + N);

    
    int st = 0, en = 0x7f7f7f7f; 
    int mid;
    while(st < en){
        mid = (st + en + 1 ) /2;
        // cout << " st, mid, en : " << st << ", " << mid << ", " << en << ", solve :  "<< solve(mid) << "\n";
        // cout << "solve , C : "<< solve(mid)<< " " << C << "\n";
        if(solve(mid) < C){
            en = mid -1 ;
        }
        else{
            st = mid;
        }

    }
    cout << en;

}