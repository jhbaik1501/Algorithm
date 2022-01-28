#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#define X first;
#define Y second;
using namespace std;

int N, M;
int DFS[1001][1001];
int check[1001][1001][2];
int cost[1001][1001];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main(){
    cin >> N >> M;
    string s = "";

    for(int i = 0; i < N; i++){
        cin >> s;
        for (int j = 0; j < M; j++){
            DFS[i][j]= s[j] - '0';
        }
        s = "";
    }
    if(N == 1 && M == 1){
        cout << "1";
        return 0;
    }
    queue<pair<pair<int,int>,int>> Q;
    Q.push({{0,0}, 0});
    
    pair<pair<int, int>,int> temp;
    check[0][0][0] = 1;
    cost[0][0] = 1;
    
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        cout << "temp "<<temp.first.first << ", " << temp.first.second << ", "<<temp.second <<"\n";
        for(int i =0; i< 4; i++){
            int x = dx[i] + temp.first.first;
            int y = dy[i] + temp.first.second;

            if(x == N-1 && y == M-1){ 
                //도착한 경우!
                cout<< cost[temp.first.first][temp.first.second] + 1;
                return 0;
            }
            if(x >= N || y >= M || x < 0 || y < 0) continue;
            if(temp.second == 0){
                //벽을 아직 부수지 않은 경우
                //cout << check[x][y] << ", " << DFS[x][y] << "\n";
                if(check[x][y][0] == 0 && DFS[x][y] == 0){
                    //벽을 부수지 않았는데, 벽이 아닌 경우
                    check[x][y][0] = 1;
                    Q.push({{x,y}, 0});
                    cost[x][y] = cost[temp.first.first][temp.first.second] + 1;
                }
                else if(check[x][y][1] == 0 && DFS[x][y] == 1){
                    //벽을 부수지 않았는데, 벽인 경우
                    check[x][y][1] = 1;
                    Q.push({{x,y}, 1});
                    cost[x][y] = cost[temp.first.first][temp.first.second] + 1;
                }
            }
            else{
                //벽을 부순 경우
                if(check[x][y][1] == 0 && DFS[x][y] == 0){
                    check[x][y][1] = 1;
                    Q.push({{x,y}, 1});
                    cost[x][y] = cost[temp.first.first][temp.first.second] + 1;
                }

            }

        }

    }

    cout << "-1";

}