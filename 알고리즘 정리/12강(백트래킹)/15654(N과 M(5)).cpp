#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;
int N , M;
int arr[9];

int ans[9];
int check[9];
void DFS(int depth){

    if(depth == M){
        for(int i=0; i< M; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    else{
        for(int i=0; i<N; i++){
            if(check[i] == 1) continue;
            
            ans[depth] = arr[i];
            
            check[i] = 1;
            DFS(depth+1);
            check[i] = 0;
        }
    }

}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    // for(int i=0; i<N; i++){
    //     cout << arr[i];
    // }

    DFS(0);
    
}

/*
3 0
1 2 3
*/