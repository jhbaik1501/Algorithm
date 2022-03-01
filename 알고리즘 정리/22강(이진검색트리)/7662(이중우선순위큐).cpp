#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int T, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    
    while(T--){
        multiset<int> ms;    
        int num;
        char ch;
        int temp;
        cin >> num;
        while(num--){
            cin >> ch >> temp;
            if(ch == 'I'){
                ms.insert(temp);
            }
            else{
                if(ms.empty()){
                    continue;
                }
                if(temp ==1){
                    ms.erase(prev(ms.end()));
                }
                else{
                    ms.erase(ms.begin());
                }
            }
        }

        if(ms.empty()){
            cout << "EMPTY" <<"\n";
        }
        else{
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
        }
    }
    
}