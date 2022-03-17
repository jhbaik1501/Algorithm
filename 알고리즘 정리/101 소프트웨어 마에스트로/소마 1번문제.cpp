#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

struct Trie 
{ 
    Trie* ch[26]; 
    int num;
    bool end; 
    Trie() {
        num = 0;
        end = false; 
        for (int i = 0; i < 26; i++) 
            ch[i] = NULL; 
    } 
    ~Trie() { 
        for (int i = 0; i < 26; i++)
            if (ch[i]) delete ch[i]; 
    } 

    void insert(const char* s) {

        if (!*s) {
            this->end = true; 
            return;
        }
        int now = *s - 'A'; 
        if (!ch[now]) {
            ch[now] = new Trie; 
            ch[now]->num = 1;
        }
        else{
            ch[now]->num++;
        
        }
        
        ch[now]->insert(s + 1); 
    }
    
    bool find(const char* s, int len, int depth) { 
        
        if(depth == len-1) {
            
            int now = *s - 'A'; 
            cout << ch[now]->num << "\n";
            return true;
        }

        int now = *s - 'A'; 
        if (!ch[now]) 
            return false; 
        return ch[now]->find(s + 1, len, depth+1); 
    } 
}; 

int N, M;
int main(void) {

    cin >> N >> M;

    Trie* root = new Trie; 

    for(int i=0; i< N; i++){
        string s; 
        cin >> s;
        root->insert(s.c_str());
    }
    
    for(int i=0; i< M; i++){
        string tmp; 
        cin >> tmp;
        int len = tmp.length();
        if (root->find(tmp.c_str(), len, 0) ){

        }
        else{
            cout << 0 << "\n";
        }
    }
    
    delete root; 
}

/*

4 5
S
SOFT
MAESTRO
SOFTWARE

S
MAE
MMM
KKK
SOFT

3
1
0
0
2
 
*/