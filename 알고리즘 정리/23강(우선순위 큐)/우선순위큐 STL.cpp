/* 에라토스테네스의 체 이용 */
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


struct cmp{
    bool operator()(pair<int, int> a, pair <int, int> b){
        return a.second > b.second;
    }
};

int main(){
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({2, 5});
    pq.push({3, 6});
    pq.push({1, 10});
    
    while(!pq.empty()){
        cout << pq.top().first << ", " << pq.top().second << "\n";
        pq.pop();
    }
}