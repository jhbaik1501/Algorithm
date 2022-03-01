#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
int ans[9];
int check[9];

void DFS(int depth, int st){

    if(depth == M){
        for(int i=0; i<M; i++){

            
            
        }
            
        
        
        return;
    }
    
    for(int i=st; i<arr.size(); i++){
        if()
    }
}



int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    
    DFS(0, 0);

    // 1 7 9 9

    /*
        1 7
        1 9
        7 9
        9 9
    */
}

/*
3 0
1 2 3
*/