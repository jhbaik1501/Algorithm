#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[32010];
int indegree[32010];
int check[32010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;    
    
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> Q;
    for(int i=1; i<N+1; i++){
        if(indegree[i] == 0){
            Q.push(i);
        }
    }

    while(!Q.empty()){
        int temp = Q.front();
        cout << temp << " ";
        Q.pop();
        for(int i=0; i<graph[temp].size(); i++){
            indegree[graph[temp][i]]--;
            if(indegree[graph[temp][i]] == 0){
                Q.push(graph[temp][i]);
            }
        }

    }

    

}