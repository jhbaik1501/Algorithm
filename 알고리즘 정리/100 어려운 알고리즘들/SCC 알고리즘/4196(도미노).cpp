#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;


int T, N, M;
int check[100010];
stack<int> S;

vector<int> graph[100010];
vector<int> graph_reverse[100010];

void DFS(int n){

    if(check[n] == 1) return;    
    check[n] = 1;
    for(auto node : graph[n]){
        DFS(node);
    }
    
    S.push(n);
}

void DFS_(int n){

    if(check[n] == 1) return;    
    check[n] = 1;
    for(auto node : graph[n]){
        DFS(node);
    }

}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;

    while(T--){
        cin >> N >> M;

        

        for(int i=0; i <M; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph_reverse[b].push_back(a);
        }

        for(int i=1; i<= N; i++){
            if(check[i] == 1) continue;
            DFS(i);
        }
        
        fill(check, check+100010, 0);
        
        int ans = 0;

        while(!S.empty()){
            int temp = S.top(); S.pop();
            if(check[temp] == 1) continue;
            ans++;
            DFS_(temp);
        }
        
        cout << ans;

    }
}