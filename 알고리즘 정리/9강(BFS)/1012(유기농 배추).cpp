#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int T; //테스트 갯수
int M, N, K; // 가로길이, 세로길이, 배추 위치 갯수

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){
    int arr[51][51] = {0, };
    int check[51][51] = {0, };
    cin >> M >> N >> K;
    int a, b;
    while(K--){
        cin >> a >> b;
        arr[a][b] = 1;
        
    }

    // for(int i=0; i<M; i++){
    //     for(int j=0; j<N;j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    queue<pair<int, int>> Q;
    int ans = 0;

    for(int i=0; i<M; i++){
        for(int j=0; j<N;j++){
            if(arr[i][j] == 1 && check[i][j] == 0){
                //cout << "i,j : "<< i << ", "<<j << "\n";
                check[i][j] = 1;
                Q.push({i,j});
                ans++;
                while(!Q.empty()){
                    pair<int, int> p = Q.front();
                    Q.pop();
                    for(int k=0; k<4; k++){
                        int x = p.first + dx[k];
                        int y = p.second + dy[k];
                        if(x >= M || y >= N || x < 0 || y < 0) continue;
                        if(check[x][y] != 0 || arr[x][y] != 1) continue;
                        
                        check[x][y] = 1;
                        Q.push({x,y});
                    }
                }

            } 
        }
    }

    cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        BFS();
    }
    
    
}
