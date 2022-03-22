#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main(){
    
    
    
    string str;
    str += "11";
    str += "i'm jonghyun ! nice to meet you";
    reverse(str.begin(), str.end());
    str.pop_back();
    str.replace(2, 1,"HIHIHIHIHIHI");

    float k = 324.35;
    str += "\t  ";
    
    str += to_string(k);

    string s = "348";
    int i = stoi(s);
    cout << str << "\n";
    cout << i;

}

/*

5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

*/