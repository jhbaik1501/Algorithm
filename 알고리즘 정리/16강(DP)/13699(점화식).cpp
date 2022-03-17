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

using namespace std;


int n;
long long DP[40];

void bottom_up(int i){

    
    for(int j=0; j < i; j++){
        DP[i] += DP[j] * DP[i-j-1];
    }
    
    if(i == n) {
        cout << DP[i]; 
        return;
    }
    bottom_up(i+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    DP[0] = 1;
    
    if(n != 0)
        bottom_up(1);
    else{
        cout << 1;
    }
}
// 3116285494907301262
// 812944042149730764