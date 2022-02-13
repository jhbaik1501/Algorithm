#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
using namespace std;

int N, M;
int arr[9][9];
int check[9][9];
int check_camera[9];
int times_[6] = {0, 4, 2, 4, 4, 1}; 
int answer = 100;
int k = 0;
vector<pair<int, int>> camera;
vector<int> times;


int dj[4] = {0, 0, 1, -1};
int di[4] = {1, -1, 0, 0};


queue<pair<int,int>> move(int i, int j, int t, queue<pair<int,int>> Q){
    while(check[i][j] != 2 && i < N && j < M && i >= 0 && j >= 0){
            
            if(check[i][j] == 1) {
                i += di[t];
                j += dj[t];
                continue;
            }
            else {
                check[i][j] = 1;
                Q.push({i,j});
                i += di[t];
                j += dj[t];
                k++;
            }
    }
    return Q;
}

queue<pair<int,int>> checking_blind_spot(pair<int, int> ca, int t, queue<pair<int,int>> Q){
    int number = arr[ca.first][ca.second];
    int i = ca.first;
    int j = ca.second;

    if(number == 1){
        Q= move(i,j,t,Q);
    }

    else if(number == 2){
        
        if (t == 0){
            Q = move(i,j,0,Q);
            Q = move(i,j,1,Q);
        }
        else if (t == 1){
            Q = move(i,j,2,Q);
            Q = move(i,j,3,Q);
        }
    }
    else if(number == 3){
        if (t == 0){
            Q=move(i,j,0,Q);
            Q=move(i,j,2,Q);
        }
        else if (t == 1){
            Q=move(i,j,0,Q);
            Q=move(i,j,3,Q);
        }
        else if (t == 2){
            Q=move(i,j,1,Q);
            Q=move(i,j,2,Q);
        }
        else if (t == 3){
            Q=move(i,j,1,Q);
            Q=move(i,j,3,Q);
        }
    }

    else if(number == 4){
        if (t == 0){
            Q=move(i,j,0,Q);
            Q=move(i,j,1,Q);
            Q=move(i,j,2,Q);
        }
        else if (t == 1){
            Q=move(i,j,0,Q);
            Q=move(i,j,1,Q);
            Q=move(i,j,3,Q);
        }
        else if (t == 2){
            Q=move(i,j,3,Q);
            Q=move(i,j,2,Q);
            Q=move(i,j,0,Q);
        }
        else if (t == 3){
            Q=move(i,j,3,Q);
            Q=move(i,j,2,Q);
            Q=move(i,j,1,Q);
        }
    }

    else if(number == 5){
        Q=move(i,j,0,Q);
        Q=move(i,j,1,Q);
        Q=move(i,j,2,Q);
        Q=move(i,j,3,Q);
    }
    return Q;

}

queue<pair<int,int>> checking_blind_spot_remove(queue<pair<int,int>> Q){
    
    while(!Q.empty()){
        pair<int,int> temp= Q.front();
        Q.pop();
        check[temp.first][temp.second] = 0;
        k--;
    }
    return Q;
}

int recursive(int depth){
    if(depth == 0){ 
        int a = M*N - k;
        if(answer > a){
            answer = a;
        }
        return 0;
    }
    
    for (int i =0; i< times.at(depth-1); i++){
        queue<pair<int,int>> Qi;
        Qi = checking_blind_spot(camera.at(depth-1), i, Qi);
        recursive(depth-1);
        checking_blind_spot_remove(Qi);
    }
    
}

int main(){
    clock_t start, end;
    double result;
    start = clock();

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i =0; i <N; i++){
        for (int j =0; j< M; j++){
            
            cin >> arr[i][j];
            int idx = arr[i][j];
            
            if (idx >= 1 && idx <= 5){
                
                camera.push_back({i,j});
                times.push_back(times_[idx]);
                k++;
                check[i][j] = 1;
                
            }
            else if(idx == 6){
                k++;
                check[i][j] = 2;
                
            }

        }
    }

    
    recursive(camera.size());
    cout << answer;

    end = clock(); //시간 측정 끝
    result = (double)(end - start);
    printf("%f", result);
}

/*
3 0
1 2 3
*/