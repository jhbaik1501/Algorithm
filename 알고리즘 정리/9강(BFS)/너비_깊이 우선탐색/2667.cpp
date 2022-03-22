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

int N;
int DFS[26][26];
int check[26][26];

int depart_num = 0;
int answer[100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(pair<int, int> p){
    check[p.first][p.second] = 1;
    int idx = 0;
    queue<pair<int, int>> Q;
    Q.push(p);
    while(!Q.empty()){
        pair<int, int> temp = Q.front();
        Q.pop();
        idx++;
        for(int i =0; i< 4; i++){
            int x = temp.first + dx[i];
            int y = temp.second + dy[i];
            //cout << temp.first << temp.second <<"/ "<<x << ", "<< y << "\n";
            if(x >= N || y >= N || x < 0 || y < 0) continue;
            if(check[x][y] == 0 && DFS[x][y] == 1) {
                //체크값이 0이고 DFS가 1인 경우,
                
                check[x][y] = 1;
                
                Q.push({x,y});
            }
        }
    }

    return idx;

}

int main(){
    cin >> N;
    
    pair<int,int> temp;
    
    for(int i =0; i< N; i++){
        string s = "";
        cin >> s;
        for (int j =0; j < N; j++){
            DFS[i][j] = s[j] - '0';
            
        }
    }

    // cout << "DFS start\n" ;
    // for (int i =0; i< N; i++){
    //     for (int j = 0; j < N; j++){
    //         cout << DFS[i][j];
    //     }
    //     cout << "\n";
    // }
    // cout << "DFS end\n" ;
    
    for(int i =0; i< N; i++){
        for (int j =0; j < N; j++){
            
            if(check[i][j] == 0 && DFS[i][j] ==1){
                
                answer[depart_num] = BFS({i,j});
                //cout << answer[depart_num];
                depart_num++;
            }
        }
    }

    sort(answer, answer+depart_num);
    cout << depart_num << "\n";
    for(int i= 0; i < depart_num; i++){
        cout << answer[i] << "\n";
    }
   
    
}