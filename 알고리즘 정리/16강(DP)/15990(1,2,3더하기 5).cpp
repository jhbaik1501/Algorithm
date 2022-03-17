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

int T;
int n;
long long DP[100010][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    DP[1][1] = 1;
    DP[2][2] = 1;
    DP[3][1] = 1;
    DP[3][2] = 1;
    DP[3][3] = 1;

    for(int i=4; i< 100010; i++){

        DP[i][1] = DP[i-1][3] + DP[i-1][2];
        DP[i][2] = DP[i-2][1] + DP[i-2][3];
        DP[i][3] = DP[i-3][2] + DP[i-3][1];
        DP[i][1] %= 1000000009;
        DP[i][2] %= 1000000009;
        DP[i][3] %= 1000000009;
        // cout << "i : " << i << " DP : " << DP[i][1] << ", " << DP[i][2] << ", " << DP[i][3] << "\n";
    }

    while(T--){
        cin >> n;
        cout << (DP[n][1] + DP[n][2] + DP[n][3]) % 1000000009 << "\n";
    }
}