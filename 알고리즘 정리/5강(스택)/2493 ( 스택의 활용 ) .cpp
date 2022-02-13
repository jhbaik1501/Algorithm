#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    stack<pair<int,int>> s;

    int val;
    cin >> val;
    s.push({val, 1});
    cout << "0 "; 
    for (int i=2; i < N+1; i++){
        cin >> val;
        
        while(!s.empty() && s.top().first < val){
            s.pop();
        }

        if(s.empty()){
            s.push({val, i});
            cout << "0" << " ";
        }
        else{
            cout << s.top().second << " ";
            s.push({val, i});
        }

    }
}