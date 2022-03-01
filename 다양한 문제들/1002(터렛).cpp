#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;

int T;
int x1, y1, r1, x2, y2, r2;
int main() { 
    cin >> T;
    while(T--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int big_r;
        if(r1 > r2) big_r = r1;
        else big_r = r2;

        if(x1 == x2 && y1 == y2 && r1 == r2) {cout << -1 << "\n"; continue;}
        int distance1 = (x1 - x2) *(x1 - x2) + (y1 - y2) * (y1 - y2);

        if((r2-r1)*(r2-r1) > distance1){ //내접
            cout << 0 << "\n";
        }
        else if((r2-r1)*(r2-r1) == distance1){
            cout << 1 << "\n";
        }
        else{ // 외접
            int distance2 = r1 + r2;
            if(distance2* distance2 < distance1){
                cout << 0 << "\n";
            }
            else if(distance2* distance2 == distance1){
                cout << 1 << "\n";
            }
            else{
                cout << 2 << "\n";
            }
        }
        
    }
}



