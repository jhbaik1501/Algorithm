#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int SCV[65][65][65];
int arr[3];

int DP(int x, int y, int z){
    
    if(x < 0) return DP(0, y, z);
    if(y < 0) return DP(x, 0, z);
    if(z < 0) return DP(x, y, 0);
    // cout << "x, y, z : " << x << ", " << y << ", " << z << " / SCV : "<< SCV[x][y][z] << "\n";

    if(SCV[x][y][z] != -1) return SCV[x][y][z];
    if(x==0 && y==0 && z==0) return 0;

    SCV[x][y][z] = 0x7f7f7f7f;
    SCV[x][y][z] = min(SCV[x][y][z], DP(x-9,y-3,z-1) + 1);
    SCV[x][y][z] = min(SCV[x][y][z], DP(x-9,y-1,z-3) + 1);
    SCV[x][y][z] = min(SCV[x][y][z], DP(x-3,y-9,z-1) + 1);
    SCV[x][y][z] = min(SCV[x][y][z], DP(x-3,y-1,z-9) + 1);
    SCV[x][y][z] = min(SCV[x][y][z], DP(x-1,y-3,z-9) + 1);
    SCV[x][y][z] = min(SCV[x][y][z], DP(x-1,y-9,z-3) + 1);

    // cout << "x, y, z : " << x << ", " << y << ", " << z << " / SCV : "<< SCV[x][y][z] << "\n";

    return SCV[x][y][z];
}

int main(){
    
    cin >> N;
    fill(&SCV[0][0][0], &SCV[64][64][64], -1);
    

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    cout << DP(arr[0], arr[1], arr[2]);
    

}