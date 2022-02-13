/* 거듭 제곱 재귀문제 */

/* 1승을 계산할 수 있다.
k승을 계산했으면 2k승과 2k+1승도 O(1)에 계산할 수 있다.*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;
long long a,b,c;

long long pow(long long a){
    return a*a;
}

long long recursive(long long A, long long B, long long C){
    if(B == 1) {
        long long ret = A%C;
        return ret;
    }
    
    long long ret = pow(recursive(A, B/2, C));
    if(B %2 == 0){
        return ret % C;
    }
    else{
        
        return (ret % C) * A %C;
    }
}

int main(){
    cin >> a >> b >> c;
    cout << recursive(a,b,c); 
    
}
