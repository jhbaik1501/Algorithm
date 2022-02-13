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
    cin >> N;
    stack<int> st;

    string command;
    
    for(int i=0; i<N; i++){
        cin >> command;
        if(command == "push"){
            int temp;
            cin >> temp;
            st.push(temp);
        }   
        else if(command == "pop"){
            if(!st.empty()){
                cout << st.top() << "\n";
                st.pop();
            }
            else
                cout << "-1" << "\n";
        } 
        else if(command == "size"){
            cout << st.size() << "\n";
        }
        else if(command == "empty"){
            cout << st.empty() << "\n";
        }
        else if(command == "top"){
            if(!st.empty()){
                cout << st.top() << "\n";
            }
            else
                cout << "-1" << "\n";
        }
    }
}