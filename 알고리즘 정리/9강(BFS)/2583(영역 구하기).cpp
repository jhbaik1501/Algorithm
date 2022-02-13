#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, K;
int arr[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    cin >> M >> N >> K;

    int a1,b1, a2, b2;
    while(K--){
        cin >> a1 >> b1;
        cin >> a2 >> b2;
        for(int i =b1; i<b2; i++){
            for(int j=a1; j<a2; j++){
                arr[i][j] = 1;
            }
        }
    }
    
    // cout << "\n";
    // for(int i=0; i<M;i++){
    //     for(int j=0; j<N; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    
    int ans =0;
    int val[100000];
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 1) continue;
            // cout << "i,j :" << i << ", " << j << "\n";
            queue<pair<int, int>> Q;
            Q.push({i,j});
            arr[i][j] = 1;
            ans++;
            int num = 0;
            while(!Q.empty()){
                pair<int,int> temp = Q.front();
                Q.pop();
                // cout << "M-1, N-1 " << M-1 << N-1 << "\n";
                num++;
                // cout << "pop : " << temp.first << ", "<<temp.second << "\n";
                for(int m =0; m<4; m++){
                    int x = temp.first + dx[m];
                    int y = temp.second + dy[m];
                    if(x >= (M) || y >= (N) || x < 0 || y < 0) continue;
                    if(arr[x][y] == 1) continue;
                    arr[x][y] =1;
                    Q.push({x,y});
                }
            }
            val[ans] = num;
        }
    }

    
    cout << ans << "\n";

    sort(val, val+ans+1);
    for(int i =1; i < ans+1; i++){
        cout << val[i] << " ";
    }

}
