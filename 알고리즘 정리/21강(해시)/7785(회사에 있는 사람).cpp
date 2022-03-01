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

int N;

bool compare(string a, string b){
    return a > b;
}

int main(){

    cin >> N;
    set<string> hash;

    
    for(int i=0; i< N; i++){
        string name;
        string temp;
        cin >> name >> temp;
        if(hash.find(name) != hash.end()){ // 안에 들어 있는거
            hash.erase(name);
        }
        else{
            hash.insert(name);
        }
    }
    
    vector<string> v={hash.begin(), hash.end()};
    sort(v.begin(), v.end(), compare);
    for(auto i : v){
        cout << i << "\n";
    }
}