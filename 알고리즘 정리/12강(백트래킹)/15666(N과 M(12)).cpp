#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int ans[9];
void dfs(int depth){
    if(depth == M){
        for(int i=0; i<M; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=0; i< v.size(); i++){
        if(depth != 0 && ans[depth-1] > v[i]) continue;
        ans[depth] = v[i];
        dfs(depth+1);
    }
}

int main(){

    cin >> N >> M;
    int num = N;
    int temp;
    for(int i =0; i<num; i++){
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    

    // for(int i=0; i< v.size(); i++){
    //     cout << v[i] << " ";
    // }
    // cout << "\n";
    dfs(0);
}

/*
3 0
1 2 3
*/