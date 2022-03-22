#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;

    map <string, int> M;
    M["one"] = 1;
    M["two"] = 2;
    M["three"] = 3;
    M["four"] = 4;
    M["five"] = 5;
    M["six"] = 6;
    M["seven"] = 7;
    M["eight"] = 8;
    M["nine"] = 9;
    
    string tmp = "";
    string ans = "";
    int idx = 0;
    for(int i=0; i< s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            ans += s[i];
            continue;
        }
        else{
            tmp += s[i];
            if(M.find(tmp) != M.end()){ // 있다면
                ans += to_string(M[tmp]);
                tmp = "";
            }
            
        }
    }
    cout << ans;

}

/*

5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

*/