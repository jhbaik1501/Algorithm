#include <stdio.h>
#include <iostream>

using namespace std;

int a1, a0, c, n0;

int f(int n){
    return a1 * n + a0;
}

int g(int n){
    return c * n;
}
int main(){
    cin >> a1 >> a0 >> c >> n0;
    for(int i = n0; i < 101; i++){
        if(!(f(i) <= g(i))){
            cout << "0";
            return 0;
        }
    }
    
    cout << "1";

}

