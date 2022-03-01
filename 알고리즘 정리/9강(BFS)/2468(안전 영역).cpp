#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>


using namespace std;

int N;
int arr[101][101];


int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
    
    int max_val = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            max_val = max(max_val, arr[i][j]);
        }
    }
    int ans = 1;

    for(int rain=0; rain<max_val; rain++){

        int check[101][101] = {0,};
        int area = 0;
        // cout << "rain : " << rain << "\n";
        for(int i=0; i< N; i++){
            for(int j=0; j<N; j++){
                if(rain < arr[i][j] && check[i][j] != 1){
                    // cout << "i, j = " << i << ", " << j << "\n"; 
                    queue<pair<int, int>> Q;
                    Q.push({i,j});
                    check[i][j] = 1;
                    area++;
                    while(!Q.empty()){
                        pair<int,int> temp = Q.front();
                        Q.pop();

                        for(int k=0; k<4; k++){
                            int x = temp.first + dx[k];
                            int y = temp.second + dy[k];
                            if(x >= N || y >= N || x <0 || y <0) continue;
                            if(check[x][y] == 1 || (rain >= arr[x][y])) continue;
                            check[x][y] = 1;
                            Q.push({x,y});
                        }

                    }

                }
            }
        }
        
        ans = max(area, ans);
        // cout << "area : "<< area << '\n';
    }
    
    cout << ans;
}
