// 감시 당하는 아파트 직원이라고 생각하면 쉽다.
// 내 차례가 왔을 때, 지켜보는 아파트, 즉 stack에 남아있는 갯수를 새야한다.

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

#define ll long long

stack<int> s;
int n;
ll ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  stack<int> S;
  cin >> n;
  int temp;
  while(n--){
    cin >> temp;
    while(!S.empty() && S.top() <= temp){
      S.pop();
    }
    ans += S.size();
    S.push(temp);
  }
  
  cout << ans;
}