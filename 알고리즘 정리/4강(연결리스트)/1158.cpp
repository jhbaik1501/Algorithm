#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int N, K;

int main(){

    ios::sync_with_stdio(0);
    cout.tie(0);
    cin >> N >> K;

    list<int> List;

    for(int i=1; i<N+1;i++){
        List.push_back(i);
    }

    cout << "<";
    auto cursor = List.begin();
    while(!List.empty()){
        for(int i=0; i< K-1; i++){
            cursor++;
            if(cursor == List.end())
                cursor = List.begin();
        }
        if(List.size() != 1){
            cout << *cursor << ", ";
        }
        else{
            cout << *cursor << ">";
        }
        cursor = List.erase(cursor);
        if(cursor == List.end())
            cursor = List.begin();
        // for (auto iter = List.begin(); iter != List.end(); iter++)
        //     cout << *iter << " ";
        // cout << "\n";
    }
}