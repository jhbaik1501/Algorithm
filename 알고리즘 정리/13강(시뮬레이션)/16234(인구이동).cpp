#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;

int N, L, R;
int arr[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans;
int prev_arr[51][51];

int compare(){
    int check[51][51];
    fill(&check[0][0], &check[50][51], 0);
    int idx = 1;
    int idx_num[2600] = {0, }; 
    int ret = 1;
    for(int i=0; i< N; i++){
        for(int j=0; j<N; j++){ 

            if(check[i][j] == 0){
                check[i][j] = idx;
                queue<pair<int,int>> Q;
                queue<pair<int,int>> reset;
                Q.push({i,j});
                int num1 = 0;
                int num2 = 0;
                int input_num = 0; // 들어가야 될 수.
                while(!Q.empty()){
                    auto temp = Q.front();
                    Q.pop();
                    num1 += arr[temp.first][temp.second];
                    num2++;
                    reset.push(temp);
                    for(int k=0; k<4; k++){
                        int x = dx[k] + temp.first;
                        int y = dy[k] + temp.second;
                        if(x >= N || y >= N || x < 0 || y < 0) continue;
                        if(check[x][y] != 0) continue; // 들른적이 있는경우는 pass.
                        int diff= abs(arr[temp.first][temp.second] - arr[x][y]);
                        if(diff > R || diff < L) continue;
                        check[x][y] = idx;
                        Q.push({x,y});
                        ret = 0;
                    }
                }
                input_num = num1 / num2;
                idx++;
                while(!reset.empty()){
                    arr[reset.front().first][reset.front().second] = input_num;
                    reset.pop();
                }
            }
        }
    }
    return ret;
}


int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L >> R;

    for(int i=0; i< N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            prev_arr[i][j] = arr[i][j];
        }
    }
    
    while(true){
        if(compare() ==1 ) {cout << ans; return 0;}
        ans++;
    }   
}



