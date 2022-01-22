//두 개의 합

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>

using namespace std;


int main(){
    list<int> L = {1,2};
    list<int>::iterator t = L.begin();
    L.push_front(10);
    cout << *t << '\n';
    L.push_back(5);
    L.insert(t, 6);
    
     
    

    
    
}
