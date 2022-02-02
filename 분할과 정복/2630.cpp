#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;


int N;
int arr[129][129];
int white =0, blue = 0;

void recursive(int x_start, int y_start, int K){

    int temp = arr[x_start][y_start];

    int escape = 0;
    for(int i = x_start; i < x_start + K; i++){
        for(int j = y_start; j< y_start + K; j++){
            if(temp != arr[i][j]){
                escape = 1;
                break;
            }
        }
        if(escape == 1){
            break;
        }
    }

    if(escape == 0){
        if(temp == 1){
            blue++;
            return;
        }
        else{
            white++;
            return;
        }
    }

    recursive(x_start, y_start, K/2);
    recursive(x_start, y_start +K/2, K/2); 
    recursive(x_start+K/2, y_start, K/2);
    recursive(x_start +K/2, y_start + K/2, K/2);
}


int main(){
    cin >> N;
    for (int i =0; i< N; i++){
        for(int j =0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    recursive(0, 0, N);
    cout << white << "\n"<< blue;


}

