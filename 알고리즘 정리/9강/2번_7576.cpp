/*토마토 문제*/
/* 이 문제는 BFS로 풀어야한다. 왜냐하면 토마토가 자란 지점(1) 에서 모든 지점을 전부 지나는, 최단으로 지나는 거리를 알아야하기 때문에,
BFS를 사용해야한다.*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int board[1001][1001];
int check[1001][1001];
int days[1001][1001];
int m;
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> start_point;


int max(int a, int b){
    if (a > b)
        return a;
    else 
        return b;
}
int main(){
    cin >> n >> m;

    for (int i =0; i< m; i++)
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
            if (board[i][j] == 1){
                start_point.push_back({i,j});
            }
            if (board[i][j] == -1){
                check[i][j] = 1;
            }
        }
    

    if(start_point.empty()){
        for (int i =0; i< m; i++)
            for (int j = 0; j < n; j++){
                if (board[i][j] == -1) continue;
                else {
                    cout << "-1";
                    return 0;
                }
                
            }
        cout << "0";
    } //1이 한개도 존재하지 않는 경우 

    queue<pair<int,int>> Q;
    while(!start_point.empty()){
        pair<int,int> temp = start_point.back();
        start_point.pop_back();
        check[temp.first][temp.second] = 1;
        Q.push(temp);
    }

    while(!Q.empty()){
        pair<int,int> temp = Q.front();
        Q.pop();
        //cout << temp.first << "," << temp.second << "\n";
        for (int i =0; i< 4; i++){
            int first = temp.first + dx[i];
            int second = temp.second + dy[i];
            if(first < 0 || second < 0 || second >= n || first >= m) continue;
            if(check[first][second] == 1) continue;
            check[first][second] = 1;
            days[first][second] = days[temp.first][temp.second] +1;
            Q.push({first, second});
        }

    }

    int answer = 0;
    for (int i =0; i< m; i++){
        for (int j =0; j< n; j++){
            if (check[i][j] == 0){
                cout << "-1";
                return 0;
            }
            answer = max(days[i][j], answer);
        }
    }
    
    cout << answer;
    
}
