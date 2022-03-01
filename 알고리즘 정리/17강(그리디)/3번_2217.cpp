#include <iostream>
#include <algorithm>

using namespace std;


int rope[100002];
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int idx= 0;
    for(int i=0;i<n;i++){
        cin >> rope[i];
    }
    sort(rope, rope+n);
    for(int i=1;i<n+1;i++){
        idx = max(rope[n-i] * i, idx);
   } 
   cout << idx;
}