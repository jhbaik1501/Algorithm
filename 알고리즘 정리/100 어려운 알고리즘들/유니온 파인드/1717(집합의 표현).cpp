#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string s1, s2;

int table[1000100];
int n, m;

int find(int n){
    if(table[n] == n) return n;
    return table[n] = find(table[n]);
}

void merge(int a, int b){
    int m = find(a);
    int n = find(b);
    if(m == n) return;
    table[m] = n;
}


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i=0; i<= n; i++){
        table[i] = i;
    }

    for(int i=0; i<m; i++){
        int com, a, b;
        cin >> com >> a >> b;
        if(com == 0){
            merge(a,b);
        }
        else{
            // cout << "a,b : " << a <<", "<< b << ", find a,b : " << find(a) <<", " << find(b) << "\n";
            if(find(b) == find(a)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }

    }

}