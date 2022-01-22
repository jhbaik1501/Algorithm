#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, M, V;
    cin >> N >> M >> V;
    int V1 = V;
    //printf("%d %d %d", N,M,V);
    int check[10001] = {0, };
    vector<int> Edge[10001];

    if (N == 1){
        cout << V << "\n";
        cout << V ;
        return 0;
    }
    
    int a,b;
    for(int i =0; i< M; i++){
        cin >> a >> b;
        Edge[a].push_back(b);
        sort(Edge[a].begin(), Edge[a].end());
        Edge[a].erase(unique(Edge[a].begin(),Edge[a].end()), Edge[a].end());
        Edge[b].push_back(a);
        sort(Edge[b].begin(), Edge[b].end());
        Edge[b].erase(unique(Edge[b].begin(),Edge[b].end()), Edge[b].end());
    }

    if (M == 1 && (V != a && V !=b)){
        cout << V << "\n";
        cout << V ;
        return 0;
    }

    int oi = 1;
    
    vector<int> stack;

    printf("%d ", V);
    while(oi < N){
        check[V] = 1;
        
        
        int index = 0;
        int old_edge = Edge[V].size();
        for (int i =0; i< Edge[V].size(); i++){
            
            //cout << "HI:" << V << "    " ;
            if (check[Edge[V].at(i)] == 0){
                
                stack.push_back(V);                
                V = Edge[V].at(i);
                        
                printf("%d ", V);
                oi++;
                break;
            }
            index++;
            
        }
        if (index == old_edge){
            
            if (stack.size() == 0){
                break;
            }
            V = stack.back();
            stack.pop_back();
            // cout << "HI:" << V << ";" ;    
            
        }
        
    }




    for (int i = 0; i< N+2; i++){
        check[i] = 0;
    }
    oi = 0;
    printf("\n");
    V = V1;
    vector<int> queue;
    check[V] = 1;
    printf("%d ", V);
    oi++;
    for (int i =0; i< Edge[V].size(); i++){
        //cout << "\n" <<Edge[V].at(i) << "\n";
        queue.push_back(Edge[V].at(i));
        check[Edge[V].at(i)] = 1;
        //printf("%d ", Edge[V].at(i));
    }

    while(oi < N){
        if (queue.size() != 0){
            V = queue.front();
            queue.erase(queue.begin());
        }
        cout << V << " ";
        oi++;
        

        
        for (int i =0; i< Edge[V].size(); i++){

            if (check[Edge[V].at(i)] == 0){ 
                queue.push_back(Edge[V].at(i));
                check[Edge[V].at(i)] = 1;
            }
            
            
        }
        if(queue.size() == 0){
            break;
        }
        
    }

    //cout << "HI ZZ "<< Edge[1].at(0) << Edge[1].at(1) << Edge[1].at(2);
    return 0;
}

/*
4 5 1
1 2
1 3
1 4
2 4
3 4


1000 10 4
4 1000
1000 1
1000 2
1000 3
1000 4
4 500
4 600
2 5
5 9
1 24

4 500 600 1000 1 24 2 5 9 3
4 500 600 1000 1 2 3 24 5 9 

2 2 2
1 2
2 3
*/