#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int A, B;
bool a =false;

int BFS(int depth, int num){
    if(num == A){
        depth++;
        cout <<depth << "\n";
        a = true;
        return 0;
    }
    if (num == 0){
        //cout << "\n";
        return 0;
    }

    if(num % 10 == 1){
        //cout << num << " ";
        num /= 10;
        //cout << num << " \n";
        BFS(depth+1, num);
        
    }
    else if(num % 2 == 0){
        //cout << num << " ";
        num /= 2;
        //cout << num << " \n";
        BFS(depth+1, num);
        
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    BFS(0, B);
    if (!a){
        cout << "-1";
    }
}