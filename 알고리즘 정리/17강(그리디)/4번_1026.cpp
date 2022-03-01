#include <iostream>
#include <algorithm>

using namespace std;


int A[102];
int B[102];
int n;

bool compare(int a1, int a2){
    return a1 > a2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i <n; i++){
        cin >> A[i];   
    }

    for(int i=0; i <n; i++){
        cin >> B[i];   
    }
    sort(A, A+n);
    sort(B, B+n, compare);

    int idx =0;
    for(int i=0; i <n; i++){
        idx += A[i] * B[i];
    }

    cout << idx;


}