#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;


int N, R, Q;

vector<int> node[100100];
int DP[100100];
int check[100100];

int DFS(int n){
    
    check[n] = 1;

    if(node[n].size() == 1 && n != R) return 1;

    for(auto child : node[n]){
        
        if(check[child]) continue;
        // cout << "n : " << n << ", child : " << child << " DP[n] : "<< DP[n] << "\n";
        int temp = DFS(child);
        DP[n] += temp;
    }

    return DP[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&DP[0], &DP[100099], 1);
    cin >> N >> R >> Q;

    for(int i=0; i< N-1; i++){
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }


    DFS(R);

    

    for(int i=0; i<Q; i++){
        int temp;
        cin >> temp;
        cout << DP[temp] << "\n";
    }
}