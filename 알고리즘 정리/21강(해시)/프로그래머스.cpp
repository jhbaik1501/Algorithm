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
#include <map>
using namespace std;


int main(){

    vector<string> participant = {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion = {"stanko", "ana", "mislav"};

    multiset <string> S;

    for(auto i : participant){
        S.insert(i);
    }
    for(auto i : completion){
        S.erase(S.find(i));
    }

    for(auto i : S){
        cout << i;
    }
}