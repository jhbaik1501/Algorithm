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

unordered_map<string, pair<string,int> > parent;
int val[100100];
int T, n;

string find(string s1){
    if(parent[s1].first == s1) return s1;
    return parent[s1].first = find(parent[s1].first);
}

void merge(string s1, string s2){
    string a = find(parent[s1].first);
    string b = find(parent[s2].first);
    // cout << a << ", " << b;
    if(a == b) return;
    // cout << parent[b].second << ", "<<parent[a].second << "\n";
    parent[a].first = b;
    parent[b].second = {parent[b].second + parent[a].second};
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    
    while(T--){
        parent.clear();
        fill(val, val+100100, 0);
        cin >> n;
        
        for(int i=0; i<n; i++){
            string s1, s2;
            cin >> s1 >> s2;

            if(parent.find(s1) == parent.end()) parent[s1] = {s1, 1};
            if(parent.find(s2) == parent.end()) parent[s2] = {s2, 1};

            merge(s1, s2);
            cout << parent[find(s1)].second << "\n";
        }

    }

}