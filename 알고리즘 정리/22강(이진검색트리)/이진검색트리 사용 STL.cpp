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

using namespace std;


int main(){

    unordered_set<int> set;
    set.insert(10);
    set.insert(10);
    set.insert(100);
    set.insert(-19);
    
    cout << "unordered_set : ";
    for(auto i : set){
        cout << i << ", ";
    }
    cout << "\n";
    if(set.find(15) != set.end())
        cout << "find 15 ! \n";
    if(set.find(100) != set.end())
        cout << "find 100 ! \n";
    cout << "set Count : "<< set.count(10) << "\n";
    set.erase(10);

    cout << "unordered_set : ";
    for(auto i : set){
        cout << i << " ";
    }
    cout << "\n";

    unordered_multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(100);
    ms.insert(-19);
    
    cout << "unordered_multiset : ";
    for(auto i : set){
        cout << i << ", ";
    }
    cout << "\n";
    if(set.find(15) != set.end())
        cout << "find 15 ! \n";
    if(set.find(100) != set.end())
        cout << "find 100 ! \n";
    cout << "set Count : "<< set.count(10) << "\n";
    set.erase(10);

    cout << "unordered_set : ";
    for(auto iter = ms.begin(); iter != ms.end(); iter++){
        cout << *iter << " ";
    }
    for(auto i : set){
        cout << i << " ";
    }
    cout << "\n";

    unordered_map<string, int> map;
    map["apple"] = 123;
    map["banana"] = 200;
    cout << "map.size() : " << map.size() << '\n';
    if(map.find("apple") != map.end()) cout << "apple in map ~ " << "\n";
    for(auto i : map){
        cout << i.first << i.second <<" ";
    }
}