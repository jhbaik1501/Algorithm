#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M;

struct node{
    int value;
    int x;
    int y;

        
};

struct compare{
    bool operator()(node a, node b){
        return a.value > b.value;
    }
};


priority_queue<node, vector<node>, compare> pq;
vector<pair<int,int>> graph[10010]; // 첫번째가 연결된가, 두번째가 비용
int V, E;
int check[10010];
int main(){
        
    node n1 = {3,1,2};
    node n2 = {2,3,2};
    node n3 = {4,4,1};
    
    pq.push(n1);
    pq.push(n2);
    pq.push(n3);
    
    cin >> V >> E;

    for(int i=0; i<E; i++){
        int value, x, y;
        cin >> x >> y >> value;
        graph[x].push_back({y, value});
        graph[y].push_back({x, value});
    }

    for(auto i : graph[1]){
        node n = {i.second, 1, i.first};
        pq.push(n);
    }
    check[1] = 1;
    int ans =0;
    int idx = 0;
    while(idx < V-1){
        // cout << "idx : " << idx  << "\n";
        auto temp = pq.top();
        if(check[temp.y]){ // 상대편을 방문한 경우, 버려 버림.
            pq.pop();
            continue;
        }
        else{ // 상대편을 방문하지 않은 경우, 
            pq.pop();
            check[temp.y] = 1;
            for(auto i : graph[temp.y]){
                if(check[i.first] == 1) continue;
                node n = {i.second, temp.y, i.first};
                pq.push(n);
            }
            
            idx++;
        }

        ans += temp.value;
    }
    
    cout << ans;
}