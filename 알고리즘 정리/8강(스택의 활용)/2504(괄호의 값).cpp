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
stack<pair<int,int>> Cal; 
int sum;

void calculate(){
    pair<int,int> temp = Cal.top();
    Cal.pop();
    // cout << "temp" << temp.first << ", "<<temp.second << "\n";

    if(temp.second == 0 && Cal.empty()){
        
        sum += temp.first;
        // cout << "Hi" << sum << "\n";
        return;
    }
    else if(!Cal.empty() && Cal.top().second == temp.second){
        // cout << "Hi";
        int k= Cal.top().first;
        Cal.pop();
        Cal.push({temp.first + k, temp.second});
        calculate();
    }
    else if(!Cal.empty() && Cal.top().second == temp.second+1){
        // cout << "Hi";
        int k= Cal.top().first;
        Cal.pop();
        Cal.push({temp.first * k, temp.second});
        calculate();
    }
    else{
        // cout << "Hi";
        Cal.push(temp);
    }

}

int main(){
    
    string str;
    cin >> str;
    stack<char> S;
    int M = str.length();
    // cout << M;

    for(int i=0; i<M; i++){

        if(str[i] == '('){
            S.push('(');
        }
        else if(str[i] == ')'){
            if(!S.empty() && S.top() == '('){
                
                S.pop();
                Cal.push({2, S.size()});
                calculate();
            }
            else {
                cout << 0;
                return 0;
            }
        }
        else if(str[i] == '['){
            S.push('[');
        }
        else{
            if(!S.empty() && S.top() == '['){
                S.pop();
                Cal.push({3, S.size()});
                calculate();
            }
            else {
                cout << 0;
                return 0;
            }
        }
        
    }
    
    if(!S.empty()){
        cout << 0;
        return 0;
    }
    cout << sum;
    
}