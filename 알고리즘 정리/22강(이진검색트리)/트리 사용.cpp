#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int T, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    
    multiset<int> ms;    
    ms.insert(10);
    ms.insert(-192);
    ms.insert(1032);
    ms.insert(-10);
    ms.insert(2340);
    ms.insert(30);
    ms.insert(10);
    
    ms.erase(prev(ms.end()));
    for(auto i : ms){
        cout << i << "\n";
    }
    
}