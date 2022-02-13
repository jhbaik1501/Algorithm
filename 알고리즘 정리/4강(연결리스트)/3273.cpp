#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int M;

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    string str;
    cin >> str;
    list<char> l;
    
    for(int i=0; i< str.length(); i++){
        l.push_back(str[i]);    
    }
    
    cin >> M;

    char command;
    auto t = l.end();

    for(int i=0;i<M;i++){

        cin >> command;

        if(command == 'L'){
            if(t != l.begin()){
                t--;
            }
        }
        else if(command == 'D'){
            if(t != l.end()){
                t++;
            }
        }
        else if(command == 'B'){
            
            if(t != l.begin()){
                t--;
                t = l.erase(t);
            }
            
        }
        else{
            char temp;
            cin >> temp;
            l.insert(t, temp);
        }

    }

    for(auto k = l.begin(); k != l.end() ;k++){
            cout << *k;
    }
}