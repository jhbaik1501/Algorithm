#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while(N--){

        string str;
        cin >> str;
        list<char> L;
        auto cursor = L.end();
        for(int i=0; i < str.length(); i++){
            
            if( str[i] == '<'){
                if(cursor != L.begin()){
                    cursor--;
                }
            }
            else if ( str[i] == '>'){
                if(cursor != L.end())
                    cursor++;
            }
            else if (str[i] == '-'){
                if(cursor != L.begin()){
                    cursor--;
                }
                cursor = L.erase(cursor);
            }
            else{
                
                L.insert(cursor, str[i]);
                
                

                // for(auto iter = L.begin(); iter != L.end(); iter++)
                //     cout << *iter;
                // cout << "\n";
            }
        }
        for(auto iter = L.begin(); iter != L.end(); iter++)
            cout << *iter;
        cout << "\n";
    }
}