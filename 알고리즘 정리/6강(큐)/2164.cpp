#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
using namespace std;


int N;
int main(){
    cin >> N;
    queue<int> Q;
    for(int i=1; i<N+1;i++)
        Q.push(i);
    
    while(Q.size() >= 1){
        if(Q.size() == 1) break;
        Q.pop();
        if(Q.size() == 1) break;
        Q.push(Q.front());
        Q.pop();
    }

    int k = Q.front();
    cout << k;
}