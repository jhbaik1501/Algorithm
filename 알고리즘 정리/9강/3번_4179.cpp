#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int board[1001][1001]; // 
int cost[1001][1001];
int check1[1001][1001];
int check2[1001][1001];
int m; //행
int n; //열
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){

    
    
    queue<pair<int,int>> FQ;
    queue<pair<int,int>> JQ;
    cin >> m >> n;
    string k;
    for(int i= 0; i < m; i++){
        cin >> k;
        for (int j =0; j < n; j++){
            
            if(k[j] == 'F'){
                board[i][j] = 0;
                FQ.push({i,j});
                check1[i][j] = 1;
                check2[i][j] = 1;
            }
            else if(k[j] == 'J'){
                JQ.push({i,j});
                check2[i][j] = 1;
            }
            else if(k[j] == '#'){
                check1[i][j] = 1;
                check2[i][j] = 1;
            }
        }
    }
    
    while(!FQ.empty()){
        pair<int,int> temp = FQ.front();
        FQ.pop();
        //cout << temp.first << ", "<<temp.second << "-> cost "<<board[temp.first][temp.second] <<" (FIRE )\n";
        for(int i =0; i< 4; i++){
            int first = temp.first + dx[i];
            int second = temp.second + dy[i];
            if(first >= m || second >= n || first < 0 || second <0) continue;
            if(check1[first][second] == 1) continue;
            board[first][second] = board[temp.first][temp.second] + 1;
            check1[first][second] = 1;
            FQ.push({first, second});
        }
    }

    while(!JQ.empty()){
        pair<int,int> temp = JQ.front();
        JQ.pop();
        //cout << temp.first << ", "<<temp.second << "-> cost "<< cost[temp.first][temp.second] <<"\n";
        for(int i =0; i< 4; i++){
            //cout << "HI";
            int first = temp.first + dx[i];
            int second = temp.second + dy[i];
            if(first >= m || second >= n || first < 0 || second <0){ // 탈출
                cout << cost[temp.first][temp.second] +1 ;
                return 0;
            }
            if(check2[first][second] == 1) continue;
            if((cost[temp.first][temp.second] +1) >= board[first][second] && board[first][second] != 0) continue;
            cost[first][second] = cost[temp.first][temp.second] + 1;
            check2[first][second] = 1;
            JQ.push({first, second});
        }
    }
    cout << "IMPOSSIBLE";
}
/*
4 4
###F
#J.#
#..#
#..#
*/