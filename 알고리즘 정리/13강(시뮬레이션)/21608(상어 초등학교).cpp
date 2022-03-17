#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


int N;
int arr[23][23];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void locate(int tar, int p1, int p2, int p3, int p4){

    int maxi = -1;
    int not_locate = 0;
    int X = 0;
    int Y = 0;
    for(int i=0; i < N; i++){
        for(int j=0;  j < N; j++){
            
            if(arr[i][j] == 0){

                // cout << "i, j : " << i << ", " << j << "\n";
                int like = 0;
                int not_in = 0;
                for(int k =0; k <4; k++){
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                    if(x >= N || x < 0 || y >= N || y < 0) continue;
                    if(arr[x][y] == p1 || arr[x][y] == p2 || arr[x][y] == p3 || arr[x][y] == p4){
                        like++;
                    }
                    if(arr[x][y] == 0){
                        not_in++;
                    }
                }
                
                if(maxi == -1){
                    maxi = like;
                    not_locate = not_in;
                    X = i;
                    Y = j;
                }
                else if(maxi < like){
                    maxi = like;
                    X = i;
                    Y = j;
                }
                else if(maxi == like){
                    if( not_locate < not_in){
                        not_locate = not_in;
                        X = i;
                        Y = j;
                    }
                }
                
                // cout << "not_locate, not_in, maxi, like  : " << not_locate << ", " <<not_in  << "," << maxi << "," << like << "\n";
                // cout << " X, Y : " << X << ", " << Y << "\n";
                
            }
            
        }
    }    
    // cout << " X, Y : " << X << ", " << Y << "\n";
    arr[X][Y] = tar;
}

int A[450][4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0; i < N*N; i++){
        int tar;
        int p1, p2, p3, p4;
        cin >> tar >> p1 >> p2 >> p3 >> p4;
        locate(tar, p1, p2, p3, p4);
        A[tar][0] = p1;
        A[tar][1] = p2;
        A[tar][2] = p3;
        A[tar][3] = p4;
    }
    
    int ans = 0;
    for(int i=0; i < N; i++){
        for(int j=0;  j < N; j++){
            //  cout << arr[i][j] << " ";
            int like = 0;
            for(int k =0; k <4; k++){
                int x = dx[k] + i;
                int y = dy[k] + j;
                if(x >= N || x < 0 || y >= N || y < 0) continue;
                if(arr[x][y] == A[arr[i][j]][0] || arr[x][y] == A[arr[i][j]][1] || arr[x][y] == A[arr[i][j]][2] || arr[x][y] == A[arr[i][j]][3]){
                    like++;
                }
            }
            if(like == 1) ans++;
            if(like == 2) ans+=10;
            if(like == 3) ans+=100;
            if(like == 4) ans+=1000;
        }
        //  cout << "\n";
    }
    cout << ans;

}