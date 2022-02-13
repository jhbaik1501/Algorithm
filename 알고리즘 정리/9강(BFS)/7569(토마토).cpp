#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;


struct V
{
    int x;
    int y;
    int z;
    int val;
};

int T;


int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int arr[101][101][101];
//int check[101][101][101];
int M, N, H;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> H;

    V v;
    
    queue<V> Q;
    for(int i=0; i< H; i++){
        for(int j=0; j < N; j++){
            for(int k=0; k < M; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    Q.push({i,j,k,0});
                    //check[i][j][k] = 1;
                    //cout << Q.front().x << Q.front().y << Q.front().z;
                }
            }
        }
    }
    
    int ans = 0;
    while(!Q.empty()){
        V temp = Q.front();
        Q.pop();
        //cout << temp.val << " : z, x, y = " << temp.x << temp.y << temp.z << "\n";
        ans = max(ans, temp.val);
        for(int i=0; i<6; i++){
            int x = temp.x + dx[i];
            int y = temp.y + dy[i];
            int z = temp.z + dz[i];
            
            if(x >= H || y >= N || z >= M || x < 0 || y < 0 || z < 0) continue;
            if(arr[x][y][z] == 1 || arr[x][y][z] == -1) continue;
            //check[x][y][z] = 1;
            arr[x][y][z] = 1;
            Q.push({x,y,z, temp.val + 1});
        }
    }

    for(int i=0; i< H; i++){
        for(int j=0; j < N; j++){
            for(int k=0; k < M; k++){
                if(arr[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << ans;



}
