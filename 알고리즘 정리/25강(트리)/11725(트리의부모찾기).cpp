#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;


vector<int> graph[100010];
int check[100010];
int ans[100010];
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> Q;
    Q.push(1);

    while(!Q.empty()){
        int temp = Q.front();
        Q.pop();
        for(auto i : graph[temp]){
            if(check[i] == 1) continue;
            ans[i] = temp;
            check[i] = 1;
            Q.push(i);
        }
    }
    for(int i=2; i<=N; i++)
        cout << ans[i] << "\n";
}