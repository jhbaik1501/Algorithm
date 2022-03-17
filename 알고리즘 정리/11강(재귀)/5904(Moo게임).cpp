#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

vector<int> V;
int N;

void recursive(int depth, int size){

    if(N < size){
        return;
    }    
    V.push_back(size);
    recursive(depth +1, size + (depth+4) + size );
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    recursive(0);

    recursive(0, 3);
}
