/* 미로 문제 */

/* 이 문제는 BFS인지 어떻게 알아차리느냐? 일단 최단거리를 구해야한다. 그런데, 모든 경우의 수를 
구해보고 최단으로 도착하는 경우를 도출해야 하므로 BFS를 사용한다. */

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int board[101][101];
int check[101][101];
int answer[101][101];
int m; //행
int n; //열
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){

    cin >> m >> n;
    string k;
    for(int i =0; i< m; i++){
        cin >> k;
        for (int j =0; j < n; j++){
            board[i][j] = k[j] - '0';
        }
    }

    
    pair<int, int> target = {m-1, n-1}; //도착지
    queue<pair<int, int>> Q;
    
    check[0][0] = 1;
    Q.push({0, 0});
    answer[0][0] = 1;

    while(!Q.empty()){
        pair<int,int> temp = Q.front();
        Q.pop();
        //cout << "(" << temp.first << "," << temp.second << ")";
        for (int i =0; i< 4; i++){
            int first = temp.first + dx[i];
            int second = temp.second + dy[i];
            if (first < 0 || second < 0 || first >= m || second >= n) continue;
            if (check[first][second] == 1 || board[first][second] != 1) continue;
            answer[first][second] = answer[temp.first][temp.second] + 1;

            check[first][second] = 1;
            Q.push({first, second});
        }

        
    }

    cout << answer[target.first][target.second];
    
    
}
