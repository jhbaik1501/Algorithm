
#include <iostream>
using namespace std;

int N, r, c;
int x,y;
int pow(int a, int b){
  int ret =1;
  for (int i=0; i<b; i++){
    ret *= a;
  }
  return ret;
}

int recursive(int n, int r, int c){
  if(n == 0){
    return 0;
  }
  int half;
  if (n != 2)
    half = n * (n/4);
  else 
    half = 1;
  
  int A = n/2;

  cout << A << " " << r <<" " << c << "\n";
  if (A > r && A > c){
    cout << "1: " << half << "\n";
    return recursive(n/2, r, c) + 0;
  }
    
  if (A <= r && A > c){
    cout << "2: " << half << "\n";
    return recursive(n/2, r/2, c) + half *2;
  }
  if (A > r && A <= c){
    cout << "3: " << half << "\n";
    return recursive(n/2, r, c/2) + half ;
  }
  if (A <= r && A <= c){
    cout << "4: " << half << "\n";
    return recursive(n/2, r/2, c/2) + half *3;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> r >> c;
  int k = pow(2, N);
  
  cout << recursive(k, r, c);
}  