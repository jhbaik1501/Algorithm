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
    int ans = N;
    while(N--){
        string str;
        cin >> str;
        stack<char> S;
        for(int i=0; i< str.length(); i++){
            if(S.empty() || (S.top() != str[i]) )
                S.push(str[i]);
            else{
                S.pop();
            }
        }

        if(!S.empty()){
            ans--;
        }

    }
    cout << ans;
}