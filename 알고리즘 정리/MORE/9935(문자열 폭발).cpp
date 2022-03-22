#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str, tar;
    cin >> str;
    cin >> tar;
    
    string ans = "";
    
    for(int i=0; i<str.length(); i++){
        
        ans += str[i];

        if(ans.back() == tar.back()){
            int cnt = 0;
            while(cnt < tar.size()){
                cnt++;
                if(ans.size()-cnt < 0) break;
                if(ans[ans.size()-cnt-1] == tar[tar.size()-cnt-1]){
                    continue;
                }
                else {
                    break;
                }
            }
            if(cnt == tar.size()){
                for(int i=0; i<cnt; i++){
                    ans.pop_back();
                }
            }
        }
        
        // cout << ans << "\n";
        
    }
    if(ans.empty()) cout << "FRULA";
    else cout << ans;
    
}