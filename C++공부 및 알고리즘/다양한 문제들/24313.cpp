#include <stdio.h>
#include <iostream>

using namespace std;

int a1, a2, c, n0;
int main(){
   cin >> a1 >> a2 >> c >> n0;
   if(c == a1){
       if(a2 > 0){
            cout << "0";
       }
       else{
           cout << "1";
       }
       return 0;
   }
   

    // n0 은 커지는 숫자
    if((c-a1) > 0){
        if(a2 <= (c-a1) * n0){
            cout << "1";
        }
        else cout << "0";
    }
    else {
        if(a2 >= (c-a1) * n0){
            cout << "0";
        }
        else cout << "1";
    }
    
    

}