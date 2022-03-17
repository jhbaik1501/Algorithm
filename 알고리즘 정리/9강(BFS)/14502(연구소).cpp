#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int arr[10][10];
int arr_[10][10];
int tmp2[70];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans;
vector<pair<int,int>> st;
vector<pair<int,int>> v;

void reset(){

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            arr_[i][j] = arr[i][j];
        }
    }  
    
    

}

void bfs(){

    queue<pair<int,int>> Q;
    for(auto i : st){
        
        Q.push(i);
    }
    
    
    while(!Q.empty()){
        auto temp = Q.front();
        Q.pop();
        
        for(int i=0; i<4; i++){
            int x = dx[i] + temp.first;
            int y = dy[i] + temp.second;
            if(x < 0 || y < 0 || x >= N || y >= M) continue;
            if(arr_[x][y] != 0) continue;
            arr_[x][y] = 2;
            Q.push({x,y});
        }
    }
    int num = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr_[i][j] == 0){
                num++;
            }
        }
    }

    ans = max(num, ans);
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    
    for(int i=0; i< N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) v.push_back({i,j});
            if(arr[i][j] == 2) st.push_back({i,j});
        }
    }

    int size = v.size();
    
    int tmp[70];
    for(int i=0; i<=size; i++){
        tmp[i] = i;
        // cout << tmp[i] << " ";
    }

    tmp2[size-1] = 1;
    tmp2[size-2] = 1;
    tmp2[size-3] = 1;    

    reset();

    do{
        
        for(int i=0; i<size; i++){
            if(tmp2[i] == 1){
                arr_[v[tmp[i]].first][v[tmp[i]].second] = 1;
            }
        }
        bfs();
        reset();
    } while(next_permutation(tmp2, tmp2 + size));

    cout << ans;
}
