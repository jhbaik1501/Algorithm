#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

long long N;
int main(){
    cin >> N;

    if(N % 7 == 2 || N % 7 == 0)
        cout << "CY";
    else
        cout << "SK";
    
}