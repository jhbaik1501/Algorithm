#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int N, M;
int a[1000003], b[1000003];
int arr[2000006];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i =0; i < N; i++)
        cin >> a[i];
    for (int i =0; i < M; i++)
        cin >> b[i];
    
    
    int aidx = 0;
    int bidx = 0;

    for (int i=0; i< M+N; i++){

        if(aidx == N) arr[i] = b[bidx++];
        else if(bidx == M) arr[i] = a[aidx++];
        else if(b[bidx] >= a[aidx]) arr[i] = a[aidx++];
        else arr[i] = b[bidx++];

    }
    for (int i=0; i< M+N; i++)
        cout << arr[i] << " ";
}

/*
3 0
1 2 3
*/