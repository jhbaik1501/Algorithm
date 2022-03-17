#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstring>
#include <string>

using namespace std;

vector<pair<int,int>> V[1010];

struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, compare> PQ;
long long d[1010];
int N, M;
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    fill(d, d+1010, 0xfffffffffff);
    for(int i=1; i<=M ; i++){
        int a, b, w;
        cin >> a >> b >> w;
        V[a].push_back({b,w});
    }
    int st, en; 
    cin >> st >> en;

    d[st] = 0;
    PQ.push({st, d[st]});

    while(!PQ.empty()){
        auto cur = PQ.top(); PQ.pop();

        if(d[cur.first] != cur.second) continue;

        for(auto next : V[cur.first]){
            if(d[next.first] <= d[cur.first] + next.second) continue;
            d[next.first] = d[cur.first] + next.second;
            PQ.push({next.first, d[next.first]});
        }
        
    }

    cout << d[en];
}