/* 1,3,4의 경우는 무조건 나의 승리, 일단 이 문제는 나의 승리를 무조건적으로 만드는 것에 집중하는 것이 좋아보인다.
반대로 5와 같은 경우를 생각해보면, 돌을 2개 만드는 경우, 즉 DP[i-1], DP[i-3], DP[i-4]가 하나라도 0인 경우를 생각해보면 승리로 만들 수 있다.
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

long long N;
int DP[1100];
int main(){
    cin >> N;

    // DP[1] = 1;
    // DP[3] = 1;

    // for(int i=4; i< N+1; i++){
    //     if(DP[i-3] == 0 || DP[i-1] == 0)
    //         DP[i] = 1;
    // }
    
    // for(int i=1; i< N+1; i++)
    //     cout << i <<" :"<< DP[i] << " ,";

    if(N %2 == 1)
        cout << "SK";
    else
        cout << "CY";
    
}