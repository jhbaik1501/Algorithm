/* 에라토스테네스의 체 이용 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int A[10010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N;i++){
        cin >> A[i];
    }
    int i =0;
    int j =0;
    int sum = A[0];
    int ans = 0;
    while(j <= N && i <= N){

        if(sum >= M){
            if(sum == M){
                cout << "i : " << i << ", j : " << j << "\n";
                ans++;
            }
            sum -= A[i];
            i++;
            
        }
        else{
            j++;
            sum += A[j];
        }

        

    }

    cout << ans;
}