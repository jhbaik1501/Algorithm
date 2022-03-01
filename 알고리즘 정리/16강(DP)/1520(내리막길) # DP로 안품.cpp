#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;




class S{
    public :
        int height;
        int x;
        int y;
};

struct compare{
    bool operator()(S a, S b){
        return a.height < b.height;
    }
};

int M, N;
int arr[501][501];
int DP[501][501];

int main(){
    
    priority_queue<S, vector<S>, compare> PQ;
    // PQ.push({50, 1, 2});
    // PQ.push({100, 4,4});
    // cout << PQ.top().height << " "<< PQ.top().x << PQ.top().y ;
    cin >> M >> N;
    for(int i=0; i < M; i++){
        for(int j=0; j <N; j++){
            cin >> arr[i][j];
            PQ.push({arr[i][j], i,j});
        }
    }

    
    while(!PQ.empty()){
        int x = PQ.top().x;
        int y = PQ.top().y;
        if(x != 0 || y != 0){
            
            
            if(x-1 >= 0 && arr[x][y] != arr[x-1][y])
                DP[x][y] += DP[x-1][y];
            if(x+1 < M && arr[x][y] != arr[x+1][y])
                DP[x][y] += DP[x+1][y];
            if(y-1 >= 0 && arr[x][y] != arr[x][y-1])
                DP[x][y] += DP[x][y-1];
            if(y+1 < N && arr[x][y] != arr[x][y+1])
                DP[x][y] += DP[x][y+1];

            // if( x== 1 && y == 3){
            //  //   cout << "HI : " << DP[x-1][y] << ", " << DP[x][y+1] << "\n";
            // }
           // cout << "x : " << x << ", y : " <<  y << " DP : "<< DP[x][y] <<"\n";
        }
        else{
            DP[0][0] = 1;
        }
        PQ.pop();
    }

    cout << DP[M-1][N-1];
}