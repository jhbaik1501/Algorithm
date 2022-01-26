#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <string>

using namespace std;

bool m = false;
string tmp = "";
string str;

int main(){
    cin >> str;
    str.append("*");
    int answer = 0;
    for (int i=0; i<= str.size(); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
            if(m){
                answer -= stoi(tmp);
                
            }
            else{
                answer += stoi(tmp);
                
            }

            if(str[i] == '-'){
                m = true;
            }
            tmp = "";
        }
        else{
            tmp += str[i];
        }
    }

    cout << answer;
}