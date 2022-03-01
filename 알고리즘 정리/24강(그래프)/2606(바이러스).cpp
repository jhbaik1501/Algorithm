#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;

vector<int> arr[101];
int check[101];
int main(){
    
    cin >> N >> M;
    for(int i=0; i<M ; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    queue<int> Q;
    Q.push(1);
    int ans = 0;
    check[1] = 1;
    while(!Q.empty()){
        int temp= Q.front();
        Q.pop();
        ans++;
        for(auto i : arr[temp]){
            if(check[i] ==1 ) continue;
            check[i] = 1;
            Q.push(i);
        }
    }

    cout << ans -1 ;
}