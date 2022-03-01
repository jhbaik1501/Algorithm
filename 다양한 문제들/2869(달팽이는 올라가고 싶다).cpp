#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;

int A, B, V;
int main() { 
    cin >> A >> B >> V;
    int tar = V - A;
    int ans = tar / (A-B);
    if(tar <= ans * (A-B)){
        cout << ans +1;
    }
    else{
        cout << ans +2;
    }
}



