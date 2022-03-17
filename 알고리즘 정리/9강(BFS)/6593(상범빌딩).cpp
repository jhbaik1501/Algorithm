#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stdio.h>

using namespace std;

int L, R, C;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

struct locate{
    int x;
    int y;
    int z;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    while(true){
        cin >> L >> R >> C;
        int arr[32][32][32];
        int ans[32][32][32];
        fill(&arr[0][0][0], &arr[31][31][31], 0);
        fill(&ans[0][0][0], &ans[31][31][31], 0);
        if(L == 0 && R == 0 && C== 0) break;
        queue<locate> Q;
        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                string str;
                cin >> str;
                for(int k=0; k<C; k++){
                    char temp = str[k];
                    
                    if(temp == '#')
                        arr[i][j][k] = 1;
                    else if(temp == 'S'){
                        arr[i][j][k] = 1;
                        Q.push({i,j,k});
                    }
                    else if(temp == 'E'){
                        arr[i][j][k] = -1;
                    }
                    
                    
                    
                }
            }
        }
        // cout << Q.front().x << Q.front().y << Q.front().z << "\n";
        int flag = 0;
        while(!Q.empty()){
            auto temp = Q.front();
            Q.pop();
            for(int i=0; i<6; i++){
                int x = temp.x + dx[i];
                int y = temp.y + dy[i];
                int z = temp.z + dz[i];

                if(x >= L || x < 0 || y >= R || y < 0 || z >= C || z < 0) continue;
                if(arr[x][y][z] == 1) continue;
                if(arr[x][y][z] == -1) {
                    cout << "Escaped in "<< ans[temp.x][temp.y][temp.z] + 1 << " minute(s).\n";
                    flag = 1;
                    break;
                }
                ans[x][y][z] = ans[temp.x][temp.y][temp.z] + 1;
                arr[x][y][z] = 1;
                Q.push({x,y,z});
            }
            if(flag == 1) break;
        }
        if(flag == 0)
            cout << "Trapped!\n";
    }
}
