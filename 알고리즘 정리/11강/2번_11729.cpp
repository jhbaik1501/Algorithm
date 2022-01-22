
#include <iostream>
using namespace std;

int A,B,C;

int hanoi(int a, int b, int n){

  if(n == 1){
    cout << a << ' ' << b << '\n';
    return 0;
  }
  hanoi(a, 6-a-b ,n-1);
  cout << a << ' ' << b << '\n';
  hanoi(6-a-b, b, n-1);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  //cin >> A >> B >> C;
  hanoi(1, 3, 3);
}