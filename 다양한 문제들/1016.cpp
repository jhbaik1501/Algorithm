#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;


int check[1000002];

int main(){
    int min;
    int max;
    cin >> min >> max;

    for (int i=2; (i*i) <= max; i++){
        int idx1 = i*i;
        cout << "\n i*i"<< idx1<<"\n";
        for (int j= 1; idx1*j <= max; j++){
            if (check[j] == 1) continue;
            int idx2 = idx1*j;
            cout << idx2 << " ";
            if(idx2 >= min || idx2 <= max){
                check[min + idx2 -1] = 1;
            }
        }
    }

    for (int i=0; i<= 100; i++){
        cout << check[i] << " ";
    }
}