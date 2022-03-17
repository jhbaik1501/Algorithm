#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string str;
int N;
int idx;
bool flag;
void Backtracking(int depth){
    if(depth == str.length()){
        idx++;
        if(idx == N){
            cout << str;
            flag = 1;
        }
        return;
    }

    if(str[depth] < str.length() - 1 ) return;
    if(depth != 0 && str[depth] >= str[depth-1] ) return;
    Backtracking(depth+1);
}

int main(){

    cin >> N;
    for(int i=0; i<987654321; i++){
        if()
        str = to_string(i);
        
        Backtracking(0);

        if(flag) return 0;
    }

    if(idx+1 == N) cout << 9876543210;
    else cout << -1;
}

/*
3 0
1 2 3
*/