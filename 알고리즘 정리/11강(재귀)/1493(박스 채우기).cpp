#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;


int L, W, H;
int N;
long long cube[22];
int cube_idx[22] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152};
// int cube_idx[22] = {2,3,5,9,17,33,65,129,257,513,1025,2049,4097,8193,16385,32769,65537,131073,262145,524289,1048577};
long long ans;
void recur(int l, int w, int h){
    
    int sh = min({l,w,h});

    if(sh == 0) return;
    int idx = 0;
    for(int i=0; i<=20; i++){
        if(sh < cube_idx[i]){
            idx = i-1;
            break;
        }
    }
    // int idx = lower_bound(cube_idx, cube_idx+19, sh) - cube_idx;
    // cout << "sh : " << sh << " idx : " << idx << "\n";

    while(cube[idx] == 0){
        idx--;

        if(idx < 0) {
            cout << "-1\n";
            exit(0);
        }
    }

    cube[idx]--;
    ans++;
    int a= cube_idx[idx];


    // recur(l-a, a, a);
    // recur(l, w-a ,a);
    // recur(l,w,h-a);

    recur(l-a, w, h);
    recur(a, w, h-a);
    recur(a, w-a, a);
    
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> L >> W >> H;
    cin >> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        cin >> cube[temp];
    }

    // for(int i=0; i< 6; i++){
    //     cout << cube[i] << " ";
    // }
    // cout << "\n";

    recur(L,W,H);
    cout << ans;

}
