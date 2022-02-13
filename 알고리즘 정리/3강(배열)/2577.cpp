#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

int A,B,C;
int arr[10];

int main(){
    cin >> A >> B >> C ;
    int m = A*B*C;
    string str = to_string(m);
    //cout << "str:" <<str;
    for(int i = 0; i< str.length(); i++){
        arr[str[i]-'0']++;
    }

    for(int i=0; i<10; i++){
        cout << arr[i] << "\n";
    }
}