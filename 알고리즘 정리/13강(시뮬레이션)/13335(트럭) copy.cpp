#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;



int n, w, L;

queue<int> truck;
int ans;
void push_bridge(){

    int weight = 0;
    queue<int> bridge;
    while (bridge.size() < w)
    {
        bridge.push(0);
    }
    while(!truck.empty()){
        
        // cout << "weight : " << weight << ", " << "bridge.front() : " << bridge.front() << ", ans : " << ans <<"\n";
        
        int truck_weight = truck.front();
        if(weight - bridge.front() + truck_weight <= L){
            ans++;
            weight += (truck_weight -bridge.front());
            bridge.pop();
            bridge.push(truck_weight);
            truck.pop();
        }
        else{
            ans++;
            weight -= bridge.front();
            bridge.pop();
            bridge.push(0);
        }
    }

}


int main() { 
    cin >> n >> w >> L;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        truck.push(temp);
    }

    
    
    push_bridge();    
    
    
    cout << ans + w;
    
}



