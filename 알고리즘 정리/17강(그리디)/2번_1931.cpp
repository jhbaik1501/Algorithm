#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#define p pair<int,int>
#define X first;
#define Y second;
using namespace std;

int N;
p S[100005];

bool compare(p a, p b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> x >> y;
        S[i] = {x,y};
    }
    sort(S, S+N, compare);

    // for (int i=0; i<N; i++){
    //      p temp = S[i];
    //      cout << temp.first << " " << temp.second << "\n";
    // }

    int idx = 1;
    p target = S[0];
    for (int i=1; i<N; i++){
        p temp = S[i];
        if(temp.first >= target.second){
            target = temp;
            idx++;
            //cout << temp.first << " " << temp.second << "\n";
        }
    }

    cout << idx;
}