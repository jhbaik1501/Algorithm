#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int arr[15];

int ans[6];
int check[15];
void DFS(int N, int depth){

    if(depth == 6) {
        for(int i=0; i<6; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=0; i<N; i++){
        if(check[i]) continue;
        if(depth != 0 && ans[depth-1] >= arr[i]) continue;
        ans[depth] = arr[i];
        check[i] = 1;
        DFS(N, depth+1);
        check[i] = 0;
        
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    while(true){
        cin >> num;
        if(!num) break;
        else{
            for(int i=0; i<num; i++){
                cin >> arr[i];
            }
        }

        DFS(num, 0);
        cout << "\n";
    }

}

