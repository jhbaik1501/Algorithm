#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stdio.h>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> N;
    cin >> str;
    
    int blue=0, red =0;
    char prev = str[0];
    if(prev == 'B'){
        blue++;
    }
    else{
        red++;
    }

    for(int i=1; i<N; i++){
        if(prev == str[i]){
            continue;
        }
        else{
            prev = str[i];
            if(prev == 'B'){
                blue++;
            }
            else{
                red++;
            }
        }
    }
    // cout << "B , R " << blue << ", " << red;
    cout << 1 + min(blue, red);
}
