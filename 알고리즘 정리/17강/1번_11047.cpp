#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int N, K;
int A[11];
int main(){
    cin >> N >> K;
    for(int i =0; i < N; i++){
        cin >> A[i];
    }

    int idx = 0;
    for(int i=N-1; i >= 0; i--){
        
        if(K < A[i]){
            continue;
        }
        else{
            idx += (K/A[i]);
            K -= ((K / A[i]) * A[i]);
        }
        if(K == 0){
            break;
        }

        
    }

    cout << idx;       
}