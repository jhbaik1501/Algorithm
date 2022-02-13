#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
using namespace std;

int notebook[41][41];
// int notebook2[41][41];
int N, M, K;
int ans;

int value[101];
int value_in[101]; 

pair<int,int> p[101];
int S[101][11][11];

void reset(int depth, int x, int y){ //되돌리는 함수
    for(int i =0; i< p[depth].first; i++){
        for(int j=0; j< p[depth].second; j++){
            if(S[depth][i][j]){
                notebook[x+i][y+j] = 0;
            }
        }
    }
}

int possible(int depth, int x, int y){ // 들어갈수 있는지 체크하는 함수

    for(int i =0; i< p[depth].first; i++){
        for(int j=0; j< p[depth].second; j++){
            if(S[depth][i][j] && notebook[x+i][y+j]){
                    return 0;
            }
            if(x+i >= N || y+j >= M) return 0;
        }
    }

    for(int i =0; i< p[depth].first; i++){
        for(int j=0; j< p[depth].second; j++){
            if(S[depth][i][j]){
                notebook[x+i][y+j] = S[depth][i][j];
            }
        }
    }
    return 1;
}

void rotation(int depth){ // 돌리는 함수
    int arr[11][11] = {0, };

    for(int i=0; i< p[depth].second; i++){
        for(int j=0; j< p[depth].first; j++){
            arr[i][p[depth].first-j-1] = S[depth][j][i];
        }
    }
    
    int k = p[depth].second; p[depth].second = p[depth].first; p[depth].first = k;

    for(int i=0; i< p[depth].first; i++){
        for(int j=0; j< p[depth].second; j++){
            S[depth][i][j] = arr[i][j];
        }
    }
    // // 잘 돌아갔는지 확인
    // cout << "\n";
    // for(int i=0; i< p[depth].first; i++){
    //     for(int j=0; j< p[depth].second; j++){
    //         cout << S[depth][i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}


void DFS(int depth){

    // if(depth == K){
    //     int sum = 0;
    //     for(int i=0; i< K; i++){
    //         if(value_in[i]){
    //             sum += value[i];
    //         }
    //     }
    //     ans = max(ans, sum);
    //     return;
    // } //스티커를 다 넣은 경우

    int possi = 0;
    for(int S = depth; S<K; S++){
        if(possi) break;
        for(int dir = 0; dir < 4; dir++){ // 4방향으로 돌려보기
            if(possi) break;
            if(dir) rotation(S);

            for(int i=0; i< N; i++){
                if(possi) break;
                for(int j=0; j<M; j++){ //모든 칸에 스티커 넣어보기
                    if(possi) break;
                    if(possible(S, i, j)){
                        possi = 1;
                        value_in[S] = 1;
                        DFS(S+1);
                        reset(S, i, j);
                        value_in[S] = 0;
                    }
                    else{
                        continue;
                    }
                }
                
            }
        
        }
        
    }

    // for(int i=0; i< N; i++){
    //     for(int j=0; j<M; j++){
    //         notebook[i][j] =0;
    //     }
    // }
    int sum = 0;
    for(int i=0; i< K; i++){
        if(value_in[i]){
            sum += value[i];
        }
    }

    
    // if(sum == 17){
    //     cout << "\n";
    //     for(int i=0; i< K; i++){
    //         if(value_in[i]){
    //             cout << "i = "<< i << "\n";
    //         }
    //     }
    //     cout << "\n";
    // }
    
    
    ans = max(ans, sum);
}

int main(){
    cin >> N >> M >> K;


    for(int k=0; k<K; k++){
        int x, y;
        int arr[11][11] = {0, };
        cin >> x >> y;
        p[k].first = x;
        p[k].second = y;
        for(int i=0; i< x; i++){
            for(int j=0; j<y; j++){
                cin >> S[k][i][j];
                if(S[k][i][j]){
                    value[k]++;
                }
            }
        }
    }

    

    // rotation(1);
    // possible(1, 0, 1);

    // cout << "\n";
    // for(int i=0; i< N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << notebook[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    // int depth = 2;
    // for(int i=0; i< p[depth].first; i++){
    //     for(int j=0; j< p[depth].second; j++){
    //         cout << S[depth][i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // rotation(depth);
    // rotation(depth);
    // rotation(depth);

    DFS(0);
    cout << ans;
}

/*
3 0
1 2 3
*/