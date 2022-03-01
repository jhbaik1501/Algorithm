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
int ans[8];

void DFS(int depth){

    if(depth == M){
        for(int i=0; i<M; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=0; i<arr.size(); i++){
        ans[depth] = arr[i];
        
        DFS(depth+1);
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
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    // cout << "arr size : "<<arr.size() << "\n";
    DFS(0);
}

/*
3 0
1 2 3
*/