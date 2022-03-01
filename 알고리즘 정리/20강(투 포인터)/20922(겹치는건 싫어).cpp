#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int N, K;
int check[100010];
int arr[200010];
int main(){
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int i=0, j=0;
    int ans = 0;
    int num = 0;
    while(i < N && j < N){

        
        if(check[arr[i]]+1 > K){
            check[arr[j]]--;
            j++;
            num--;
        }
        else{
            check[arr[i]]++;
            i++;
            num++;
            ans = max(num, ans);
        }

        // cout << " i , j , ans : " << i <<", "<< j << ", "<< num << "\n";
    }    
    
    cout << ans;
    
}