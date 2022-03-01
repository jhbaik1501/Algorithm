/* 에라토스테네스의 체 이용 */
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

    cin >> N >> M;
    multiset<string> s;
    multiset<string> s2;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    for(int i=0; i<M; i++){
        string str;
        cin >> str;
        if(s.find(str) != s.end()){
            s2.insert(str);
        }
    }
    cout << s2.size() << "\n";
    for(auto i : s2){
        cout << i << "\n";
    }

    
}