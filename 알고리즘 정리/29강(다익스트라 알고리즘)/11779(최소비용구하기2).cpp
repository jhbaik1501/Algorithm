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
    

    for(int i=0; i<E; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
    }
    int tar;
    cin >> K >> tar;
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

    cout << d[tar] << "\n";

    vector<int> v;
    
    while(tar != 0){
        v.push_back(tar);
        tar = pre[tar];
    }

    reverse(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto i : v){
        cout << i << " ";
    }
    
}

/*

5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

*/