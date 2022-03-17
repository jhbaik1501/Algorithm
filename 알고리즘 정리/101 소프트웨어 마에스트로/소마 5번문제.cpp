#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;


int main(){
    cin >> N >> M;
    deque<int> DQ;
    for(int i=0; i< N; i++){
        int temp;
        cin >> temp;
        DQ.push_back(temp);
    }
    
    sort(DQ.begin(), DQ.end());
    
    for(auto i : DQ){
        cout << i << " ";
    }

    while(M--){

        for(int i=0; i< 3; i++){
            int temp;
            cin >> temp;
            DQ.insert(lower_bound(DQ.begin(), DQ.end(), temp), temp);
        }
        
        for(auto i : DQ){
            cout << i << " ";
        }
        cout << "\n";
    }

}

/*
7 3
19 14 3 8 1 43 17
1 4 10
5 8 120
20 100 12
*/