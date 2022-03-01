#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
using namespace std;

int main(){
    string str;
    cin >> str;
    
    queue<char> S;
    int num = 0;
    int ans = 0;
    for(int i=0; i < str.length(); i++)
        S.push(str[i]);

    char prev;
    for(int i=0; i < str.length(); i++){
        
        auto temp = S.front();

        
        if(temp == '('){
            prev = temp;
            num++;
            S.pop();
        }
        else{
            num--;
            S.pop();
            
            if(prev == '('){
                ans += num;
                
            }
            else{
                ans++;
            }
            prev = ')';
        }
        
        // cout << "num, i : " << i+1 << ", "<< num << " , ans = " << ans <<"\n";
    }

    cout << ans;
}