#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, H;

int H_posi[300];


int arr[300][300];
// int dir[12][300];

int is_answer(){

    // N개 
    for(int i=1; i<=N; i++){
        int start_i = i;
        int j = 1;

        // cout << "Hi : " << arr[3][2] <<  "\n";
        while(j<= H+1){

            // cout << " i, j : "<< start_i <<", "<<  j << "\n";

            if(arr[j][start_i] == 0){
                j++;
            }
            else if(arr[j][start_i] == 1){
                start_i++;
                j++;
            }
            else{
                start_i--;
                j++;
            }

            
        }

        if(i != start_i) return 0;
    }

    return 1;
}


vector <int> ans;
vector <pair<int, int> > V;
void backtracking(int depth){


    if(is_answer() == 1){

        // for(auto i : V){
        //     cout << i.first << ", " << i.second << "\n";
        // }
        ans.push_back(depth);
        // cout << depth  << "\n";
    }

    if(depth >= 3) return;

    for(int i=1; i<= H; i++){
        for(int j=1; j< N; j++){

            // cout << " i, j : " << i << ", " << j << ", depth :" << depth; 
            if(arr[i][j] != 0) continue;
            if(arr[i][j+1] != 0) continue;
            if( !V.empty()){
                if( V.back().first > i) continue;
                if( V.back().first == i && V.back().second > j) continue;
            }

            // cout << " i, j : " << i << ", " << j << ", depth :" << depth << "\n";
            
            arr[i][j] = 1;
            arr[i][j+1] = -1;
            V.push_back({i,j});
            backtracking(depth+1);
            V.pop_back();
            arr[i][j] = 0;
            arr[i][j+1] = 0;

        }
    }

}


int main(){

    cin >> N >> M >> H;

    for(int i=0; i <M; i++){
        int a, b;
        cin >> a >> b;
        
        arr[a][b] = 1;
        arr[a][b+1] = -1;

        
    }

    // for(int i=1; i<=H; i++){
    //     for(int j=1; j<=N; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << is_answer();

    backtracking(0);

    if(ans.empty()) {
        cout << -1;
        return 0;
    }

    sort(ans.begin(), ans.end());
    cout << ans[0];
}

/*
3 0
1 2 3
*/