/*2 4 8 16 32 64 */


#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int N;

char arr[3000][3000];
void recursive(int x, int y, int size){

    if (size == 1) return;
    int plus = size/3;

    for(int i = x; i < (x+ size); i+=plus){
        for(int j=y; j < (y +size); j+=plus){

            if(i == (x+plus) && j == (y+plus)) {
                for(int m = 0; m< plus; m++){
                    for(int n=0; n<plus; n++){
                        arr[i+m][j+n] = ' ';
                    }
                }
            }
            else{
                recursive(i,j, plus);
            }
                
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for(int i=0; i<N;i++)
        for(int j=0; j< N*2; j++)
            arr[i][j] = ' ';

    recursive(0,0,N);

    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}
