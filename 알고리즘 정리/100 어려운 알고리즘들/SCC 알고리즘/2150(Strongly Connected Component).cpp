#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
vector<int> graph[10010];
vector<int> reverse_graph[10010];
int check1[10010];
int check2[10010];

vector<int> answer[10010];
int num;
stack <int> S;

void dfs(int now) { // 스택에 넣는 DFS
	check1[now] = 1;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (!check1[next])
			dfs(next);
	}
	S.push(now);
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }

    
    for (int i = 1; i <= N; i++) {
		if (!check1[i])
			dfs(i); // 방문하지 않은 점들을 DFS 돌며 스택에 값 추가
	}


    
    while(!S.empty()){
        int temp = S.top();
        S.pop();
        if(check2[temp]) continue;
        
        check2[temp] = 1;
        stack <int> ST;
        ST.push(temp);
        vector <int> ans;
        while(!ST.empty()){
            auto tmp = ST.top();
            ST.pop();
            ans.push_back(tmp);
            for(auto i : reverse_graph[tmp]){
                // cout << "i : " << i << " check2[i] : " << check2[i] << " ";
                if(check2[i] == 1) continue;
                ST.push(i);
                check2[i] = 1;
            }
        }

        sort(ans.begin(), ans.end());
        
        // for(int i : ans){
        //     cout << i << " ";
        // }
        // cout << "-1\n";
        answer[num] = ans;
        num++;
    }

    sort(answer, answer+num);
    cout << num << "\n";
    for(int i=0; i< num; i++){
        for( auto j :answer[i]){
            cout << j << " ";
        }
        cout << "-1\n";
    }

}