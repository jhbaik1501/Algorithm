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
    stack<pair<char,int>> S;
    vector<char> Q;
    int idx = 0;
    for(int i=0; i<str.length(); i++){

        
        
        if(!S.empty() && str[i] == tar[S.top().second + 1]){
            S.push({str[i], S.top().second + 1});
        }
        else if(str[i] == tar[0]){
            S.push({str[i], 0});    
        }
        else{
            if(!S.empty()){

                while(!S.empty()){
                    Q.push_back(S.top().first); S.pop();
                    
                }
            }
            Q.push_back(str[i]);
        }

        if(!S.empty()){
            cout << S.top().first << ","<< S.top().second << "  /";
        } 
        

        if(!S.empty() && S.top().second == tar.size()-1){
            
            for(int i=0; i<tar.size(); i++){
                S.pop();
                // cout << "Hi";
            }

        }

    }

    while(!S.empty()){
        Q.push_back(S.top().first); S.pop();
    }


    if(Q.empty()){
        cout << "FRULA";
    }
    else{
    for(auto i : Q){
        cout << i;
    }
    }
    
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