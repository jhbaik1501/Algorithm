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


int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--){
        string str;
        cin >> str;
        stack<char> S;
        for(auto i : str){
            if(i == '(')
                S.push('(');
            else if(i == ')' && !S.empty())
                S.pop();
            else{
                S.push(')');
                break;
            }
        }

        if(!S.empty()){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }
    }
    
}