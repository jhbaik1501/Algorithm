#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int dx[8] = {1,1,0,0,1,-1,-1,-1};
int dy[8] = {1,-1,1,-1,0,0,1,-1};
int check[51][51];
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true){
        int w, h;
        cin >> w >> h;

        int arr[51][51];
        if(w == 0 && h == 0){
            return 0;
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> arr[i][j];
                // cout << arr[i][j];
            }
            // cout << "\n";
        }
        
        int ans = 0;
        fill(&check[0][0], &check[50][51], 0);

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){

                if(arr[i][j] == 0) continue;
                if(check[i][j] == 1) continue;
                // cout << "i, j : " << i << ", " << j << "\n"; 
                ans++;
                queue<pair<int,int>> Q;
                Q.push({i,j});
                while(!Q.empty()){
                    auto temp = Q.front(); Q.pop();
                    // cout << "temp : " << temp.first << ", " << temp.second << " / arr : "<< arr[temp.first][temp.second] <<  "\n";
                    for(int i=0; i<8; i++){
                        int x = temp.first + dx[i];
                        int y = temp.second + dy[i];
                        if(x >= h || y >= w || x < 0 || y < 0) continue;
                        if(arr[x][y] == 0) continue;
                        if(check[x][y] == 1) continue;
                        check[x][y] = 1;
                        Q.push({x,y});
                    }
                }

                // cout << "\n";
            }
        }

        cout << ans << "\n";
    }

}
