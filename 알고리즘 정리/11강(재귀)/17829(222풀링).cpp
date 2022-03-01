#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int arr[1025][1025];

int max_2(int a, int b, int c, int d){

    int temp[4] = {a,b,c,d};
    sort(temp, temp+4);

    return temp[2];
}

int recursive(int x, int y, int size){
        
    if(size == 2){
        return max_2(arr[x][y], arr[x][y+1], arr[x+1][y], arr[x+1][y+1]);
    }
    
    return max_2(
        recursive(x+size/2, y, size/2), 
        recursive(x, y+size/2, size/2),
        recursive(x, y, size/2),
        recursive(x+size/2, y+size/2, size/2)
        );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    cout << recursive(0, 0, N);
}
