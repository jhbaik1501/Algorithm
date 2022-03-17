#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;

int V, E;
int K;
vector<pair<int,int>> graph[20010]; // 가중치와, 타겟 정점
int d[20010];
int pre[20010];

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(d, d+20010, INF);
    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > PQ;

    cin >> V >> E;
    cin >> K;

    for(int i=0; i<E; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
    }

    d[K] = 0;
    PQ.push({0, K});

    while(!PQ.empty()){

        auto cur = PQ.top();
        PQ.pop();
        if( d[cur.second] != cur.first) continue;

        for(auto edge : graph[cur.second]){
            if(d[edge.second] <= edge.first + d[cur.second]) continue;
            d[edge.second] = edge.first + d[cur.second];
            pre[edge.second] = cur.second;
            PQ.push({d[edge.second], edge.second});
        }
    }

    for(int i=1; i<=V; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}

/*

5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

*/