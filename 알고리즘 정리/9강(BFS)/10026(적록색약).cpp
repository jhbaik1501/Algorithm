#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int N;
char arr[101][101];
int check1[101][101]; // 색맹 아닌 사람
int check2[101][101]; // 색맹인 사람 (R = G), (B)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    
    for(int i=0; i< N; i++){
        string s;
        cin >> s;
        for(int j=0; j<N;j++){
            arr[i][j] = s[j];
            // cout << arr[i][j];
        }
        // cout << "\n";
    }
    
    int ans1 = 0;
    for(int i=0; i< N; i++){ // 색맹 아닌 사람
        for(int j =0; j< N; j++){
            if(check1[i][j] == 1) continue;
            // cout << "i, j" << i << j << "\n";
            char tar = arr[i][j];
            ans1++;
            queue<pair<int,int>> Q;
            Q.push({i,j});

            while(!Q.empty()){
                pair<int,int> p = Q.front();
                Q.pop();
                for(int k=0; k<4; k++){
                    int x = p.first + dx[k];
                    int y = p.second + dy[k];
                    // cout << "x,y" << x << y <<"\n tar :  " << tar << " arr :"<<(arr[x][y] != tar) << "\n";
                    if(x >= N || y >= N || x <0 || y <0) continue;
                    if(check1[x][y] == 1 || arr[x][y] != tar) continue;
                    
                    check1[x][y] = 1;
                    Q.push({x,y});
                }
            }

        }
    }

    for(int i=0; i< N; i++){
        for(int j=0; j<N;j++){
            if(arr[i][j] == 'G') arr[i][j] = 'R';   
        }
    }

    int ans2 = 0;
    for(int i=0; i< N; i++){ // 색맹 아닌 사람
        for(int j =0; j< N; j++){
            if(check2[i][j] == 1) continue;
            // cout << "i, j" << i << j << "\n";
            char tar = arr[i][j];
            ans2++;
            queue<pair<int,int>> Q;
            Q.push({i,j});

            while(!Q.empty()){
                pair<int,int> p = Q.front();
                Q.pop();
                for(int k=0; k<4; k++){
                    int x = p.first + dx[k];
                    int y = p.second + dy[k];
                    // cout << "x,y" << x << y <<"\n tar :  " << tar << " arr :"<<(arr[x][y] != tar) << "\n";
                    if(x >= N || y >= N || x <0 || y <0) continue;
                    if(check2[x][y] == 1 || arr[x][y] != tar) continue;
                    
                    check2[x][y] = 1;
                    Q.push({x,y});
                }
            }

        }
    }

    cout << ans1 << " " << ans2;

}
