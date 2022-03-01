#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <cstring>
#include <string>

using namespace std;
int N;
int arr[12][12];
int ans = 0x7fffffff;
int sum;
int check[12];
int st;
void Backtracking(int start, int depth){

    if(depth == N-1){
        // cout << " sum, st : " << st << ", "<<sum + arr[start][st] << "\n";
        if(arr[start][st] != 0)
            ans = min(ans, sum + arr[start][st]);
        return;
    }

    for(int i=0; i<N; i++){
        if(check[i] == 1) continue;
        if(start == i) continue;
        if(arr[start][i] == 0) continue;
        check[i] = 1;
        sum += arr[start][i];
        Backtracking(i, depth +1);
        sum -= arr[start][i];
        check[i] = 0;
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        check[i] = 1;
        st = i;
        Backtracking(i,0);
        check[i] = 0;
    }
    
    cout << ans;
}