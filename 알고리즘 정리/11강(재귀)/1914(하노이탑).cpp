/* �ŵ� ���� ��͹��� */

/* 1���� ����� �� �ִ�.
k���� ��������� 2k�°� 2k+1�µ� O(1)�� ����� �� �ִ�.*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int N;
int sum;
void Hanoi(int from, int to, int N){
    
    if(N == 0) return;
    
    Hanoi(from, 6-from-to, N-1);
    cout << from << " " << to << "\n";
    Hanoi(6-from-to, to, N-1);

    sum++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    
    long long a = 0, b=0;
    for(int i=0; i<N; i++){
        b *= 2;
		a = a * 2 + 1;
		b += a / 1000000000000000000;
		a %= 1000000000000000000;
    }
    if(b!=0)
    cout << b << a << "\n";
    else
    cout << a << "\n";
    if(N <= 20)
        Hanoi(1, 3, N);    
    
    
}
