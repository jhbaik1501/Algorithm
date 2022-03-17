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
int DP[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fill(&DP[2], &DP[100008], 0x7f7f7f7f);
    DP[1] = 1;
    for(int i=1; i < n+1; i++){
        for(int j= 1; 0 <= i - j*j; j++){
            DP[i] = min(DP[i], 1 + DP[i - j*j]); 
        }
        
    }

    cout << DP[n];
}
