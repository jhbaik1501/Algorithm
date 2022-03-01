#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

int T, n;


int main(){
    
    cin >> T;
    while(T--){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        unordered_map<string, int> map;
        for(int i=0; i<n;i++){
            string str1, str2;
            cin >> str1 >> str2;
            map[str2] += 1;
        }
        int N = 1;
        for(auto iter = map.begin(); iter != map.end(); iter++){
            // cout << iter->first << ", " << iter->second << "\n";
        }
        for(auto i : map){
            N *= (i.second +1);
        }
        
        cout << N-1 << "\n";
    }
}