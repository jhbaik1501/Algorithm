#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;

vector<int> arr[1010];
int check[1010];
int main(){
    
    cin >> N >> M;

    int first, second;
    for(int i=0; i<M; i++){
        cin >> first;
        cin >> second;

        arr[first].push_back(second);
        arr[second].push_back(first);
    }

    // for(int i=1; i<N+1; i++){
    //     cout << "i : " << i << "\n";
    //     for(int j=0; j< arr[i].size(); j++){
    //         cout << arr[i][j]<< " ";
    //     }
    //     cout << "\n";
    // }
    int ans =0;
    for(int i=1; i<N+1; i++){ //모든 정점 확인
        if(check[i] == 0){
            ans++;
            queue<int> Q;
            Q.push(i);
            check[i] = 1;

            while(!Q.empty()){
                int temp = Q.front();
                Q.pop();
                for(auto j : arr[temp]){
                    if(check[j] == 1) continue;
                    Q.push(j);
                    check[j] = 1;
                }
            }

        }
    }
    cout << ans;
}