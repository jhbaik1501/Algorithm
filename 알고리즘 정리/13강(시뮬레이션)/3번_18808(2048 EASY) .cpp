#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
using namespace std;

int N;
int arr[21][21];
int ans;
int max_val(){
    int ret =0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            ret = max(arr[i][j], ret);
        }
    }

    return ret;
}



void rotate(){
    int temp[21][21] = {0, };
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[j][N-i-1] = arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] = temp[i][j];
        }
    }
    
}

void move(){

    int num[21];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!arr[i][j]) num[i]++;
        }
    }

    for(int i=0; i< N; i++){
        int index = 0;
        int check[21] = {0, };

        for(int j=0; j<N; j++){
            // cout << "HI";
            if(arr[i][j] != 0){
                
                if(index == 0){
                    arr[i][index] = arr[i][j];
                    if(index != j) arr[i][j] = 0;
                    index++;
                    
                }
                else if(arr[i][index-1] == arr[i][j] && check[index-1] == 0){
                    arr[i][index-1] = arr[i][index-1] *2;
                    check[index-1]= 1;
                    //이동하는 경우는 내 자리를 0으로.
                    arr[i][j] = 0;
                }
                else{
                    arr[i][index] = arr[i][j];
                    if(index != j) arr[i][j] = 0;
                    index++;
                }
            }
        }
    }
    
}

void DFS(int depth){
    if(depth == 10){
        // cout << "\n";
        // for(int i=0; i<N; i++){
        //     for(int j=0; j<N; j++){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        ans = max(max_val(), ans);
        return;
    }

    for(int i =0; i<4; i++){
        if(i) rotate();
        int temp[21][21];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                temp[i][j] = arr[i][j];
            }
        }
        move();
        DFS(depth +1);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = temp[i][j];
            }
        }

    }
}


int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    

    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){

        }
    }
    DFS(0);
    cout << ans;
    // cout << "\n";
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

}
/*
4
4 4 0 16 
4 2 0 16
0 4 4 8
2 2 4 4
*/