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

int N, M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    unordered_map<string, string> map;
    string str1, str2;
    for(int i=0; i<N; i++){
        cin >> str1 >> str2;
        map[str1] = str2;
    }
    for(int i=0; i<M; i++){
        cin >> str1;
        cout << map[str1] << "\n";
    }
}