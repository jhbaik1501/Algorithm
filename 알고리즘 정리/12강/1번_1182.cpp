#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int arr[21];
int check[21];
int N, S;
int answer;
void BackTracking(int depth, int tot){
    if(depth == N){
        if(tot == S) answer++;
        //cout << tot << " -> ";
        return;
    }
    BackTracking(depth +1, tot);
    BackTracking(depth +1, tot + arr[N-depth-1]);
}

int main(){
    cin >> N >> S;
    for(int i =0; i<N; i++)
        cin >> arr[i];
    
    BackTracking(0, 0);
    if(S == 0) answer--;
    cout << answer;
}

/*
3 0
1 2 3
*/