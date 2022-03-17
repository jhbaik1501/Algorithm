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

int k;
char arr[531450] = {'-', };
int idx;
void recursive(int depth, int st, int en){

    if(depth == 0){

        return;
    }
    int temp = pow(3, depth -1);
    recursive(depth-1, st, st + temp);
    recursive(depth-1, st + temp, st + temp *2);
    // cout << "start : " << st+ temp << " end : " << st + temp * 2 << "\n";
    for(int i= st + temp; i < st+ temp*2; i++) 
    {
        
        arr[i] = ' ';
    }
    recursive(depth-1, st + temp*2, st + temp*3);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string text;

    while(true) {
        getline(cin, text);
        if(text == "") break;
        fill(&arr[0], &arr[531449], '-');
        k = stoi(text);
        recursive(k, 0, pow(3,k));
        int temp = pow(3, k);
        // cout << "tmp : " <<temp;
        for(int i=0; i< temp; i++){
            cout << arr[i];
        }
        cout << "\n";
    }
    
}
