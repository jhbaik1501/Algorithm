#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;


int N, M;
int arr[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
 
int calValue(int* check){

    
    int home_val[101] = { 0x7fffffff, };

    for(int j=0; j<home.size(); j++){
        home_val[j] = 0x7fffffff;
    }

    for(int i=0; i< M; i++){
        auto c = chicken[check[i]];
        
        for(int j=0; j<home.size(); j++){
            //집의 크기만큼 체크.
            auto h = home[j];
            int distance = abs(c.first - h.first) + abs(c.second - h.second);
            
            home_val[j] = min(home_val[j], distance);
        }
    }

    int ret =0;
    for(int j=0; j<home.size(); j++){
        ret += home_val[j];
    }

    // cout << "ret : "<< ret << "\n"; 
}

int main() { 

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                home.push_back({i,j});
            }
            else if(arr[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }

    int temp[51] = {0, };
    for(int i=0; i<M; i++){
        temp[i] = 1;
    }
    int ans = 0x7fffffff;
    int check[14];
    do{
        int idx= 0;
        for(int i=0; i< chicken.size(); i++){
            
            if(temp[i] == 1){
                check[idx] = i;
                idx++;
                // cout << i << " ";
            }
        }
        ans = min(calValue(check), ans);
        // cout << "\n";
    } while(prev_permutation(temp, temp+chicken.size()));

    cout << ans;
}



