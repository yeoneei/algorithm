//
//  5670.cpp
//  backjoon
//
//  Created by 조연희 on 24/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#define ALPABETS 26
using namespace std;
int allCount=0;
bool init=true;
struct trie{
    trie *next[ALPABETS];
    bool end;
    int cnt;
    
    trie():end(false),cnt(0){
        for(int i=0; i<ALPABETS;i++){
            next[i]=nullptr;
        }
    }
    ~trie(){
        for(int i=0; i<ALPABETS;i++){
            if(next[i]!=nullptr) delete next[i];
        }
    }
    
    void insert(const char *key){
        if(*key == '\0'){
            end=true;
            return;
        }
        int idx = *key-'a';
        if(next[idx]==nullptr){
            next[idx]=new trie;
            cnt++;
        }
        next[idx]->insert(key+1);
    }
    
    void find(const char *key){
        if(*key == '\0'){
            return;
        }
        if(init){
            init=false;
            allCount++;
        }else{
            if(cnt>1)allCount++;
            else if(end)allCount++;
        }
        int idx = *key-'a';
        next[idx]->find(key+1);
    }
};
int n;
char vc[100000][81];
trie *root;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){
        allCount=0;
        root = new trie();
        for(int i=0; i<n;i++){
            cin>>vc[i];
            root->insert(vc[i]);
        }
        for(int i=0; i<n;i++){
            init=true;
            root->find(vc[i]);
        }
        cout << fixed << setprecision(2)<< (double)allCount/(double)n<<'\n';
        delete root;
    }
    return 0;
}
