#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stdio.h>

using namespace std;

int N;

struct compare2{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        else return abs(a) > abs(b) ;
    }
};

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    map<string, float> map;
    string str;

    int sum = 0;
    while(true){
        getline(cin, str);
        if(str == "") break;
        else{
            map[str]+= 1;
            sum++;
        }
    }
    
    for(auto i : map){
        float temp = i.second* 100 / sum;
        cout << i.first << " ";
        printf("%.4f\n", temp);
        
    }
    
}
