/* 에라토스테네스의 체 이용 */

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int M, N;

int check[1000000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    check[1] = 1;
    
    vector<bool> state(N+1, true);
    state[1] = false;
    for(int i = 2; i*i <= N; i++){
        //if(check[i] == 1) continue;
        if(!state[i]) continue;
        for (int j = i*i; j <= N; j += i){
            //check[j] = 1;
            state[j] = false;
        }
    }

    for(int i = M; i <= N; i++){
        //cout << check[i] << " ";
        // if(check[i] == 0){
        //     cout << i << "\n";
        // }
        if(state[i]){
            cout << i << "\n";
        }
    }
    
}