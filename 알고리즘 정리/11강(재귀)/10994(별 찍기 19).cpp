/* 거듭 제곱 재귀문제 */

/* 1승을 계산할 수 있다.
k승을 계산했으면 2k승과 2k+1승도 O(1)에 계산할 수 있다.*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int N;
char arr[450][450] = {'\t', };
void recursive(int depth, int x, int y){
    
    if(depth == 1) {
        // cout << "HI";
        arr[x][y] = '*'; 
        return;
    }
    else{
        recursive(depth -4, x + 2 , y + 2);
        // cout << "x : " << x << " y : " << y << ", depth = "<< depth << "\n";
        for(int i=x; i< x+depth; i++){
            for(int j=y; j< y+depth; j++){
                if(i== x || i == x+depth-1 ||j== x || j == y+depth-1){
                    // cout << "HI \n";
                    arr[i][j] = '*';
                }
            }
        }
    }
    // 2,2 -> 
}

int main(){
    //1 -> 5 -> 9

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int num = 4*(N-1) + 1;
    // cout << num;
    
    recursive(num, 0, 0);
    num = 4*(N-1) + 1;
    for(int i=0; i< num; i++){
        for(int j=0; j< num; j++){
            if(arr[i][j] == '*')
            cout << '*';
            else{
                cout << ' ';
            }
            
        }
        cout << "\n";
    }
}
