#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

char arr[16];
char ans[16];
int check[16];

int L, C;
void DFS(int N, int depth){

    if(depth == L) {
        int gather = 0;
        for(int i=0; i<L; i++){
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u'){
                gather++;
            }
        }
        
        if(gather >= 1 && ( (L- gather) >= 2)){
            for(int i=0; i<L; i++)
            cout << ans[i];
            cout << "\n";
        }
        
        
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
    
    cin >> L >> C;

    for(int i=0; i<C; i++){
        cin >> arr[i];
    }

    sort(arr, arr+C);

    DFS(C, 0);

}

