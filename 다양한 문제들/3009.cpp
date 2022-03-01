#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;


int main() { 

    int a1, b1, a2, b2, a3, b3, a4, b4;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    
    if(a1 == a2) a4 = a3;
    else if(a2 == a3) a4 = a1;
    else a4 = a2;
    
    if(b1 == b2) b4 = b3;
    else if(b2 == b3) b4 = b1;
    else b4 = b2;

    cout << a4 << " " << b4;
}



