#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

struct node{
    int w;
    int x;
    int y;
};

struct compare{
    bool operator()(node a, node b){
        return a.w > b.w;
    }
};

vector< pair<int, int> > graph[1100];
int check[1100];
int N, M;
int main(){
    cin >> N >> M;
    priority_queue<node, vector<node>, compare > PQ;
    for(int i=0; i<M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    int idx = 0;
    int ans = 0;

    for(auto i : graph[1]){
        PQ.push({i.first ,1, i.second});
    }
    check[1] = 1;

    while(idx < N-1){

        auto temp= PQ.top(); PQ.pop();
        if(check[temp.y] == 1) continue;
        else{
            check[temp.y] = 1;
            ans += temp.w;
            idx++;
            // cout << temp.x << "-" << temp.y << ", ";
            for(auto i : graph[temp.y]){
                PQ.push({i.first , temp.y , i.second});
            }
            
        }
    }

    cout << ans;

}