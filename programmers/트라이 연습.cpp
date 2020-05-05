//
//  트라이 연습.cpp
//  backjoon
//
//  Created by 조연희 on 24/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#define ALPABET 10
using namespace std;

int char_to_idex(char c){
    return c-'0';
}

struct Trie{
    bool is_terminal;
    Trie *children[ALPABET];
    
    Trie():is_terminal(false){
        memset(children,0,sizeof(children));
    }
    ~Trie(){
        for(int i=0; i<ALPABET;i++){
            if(children[i]) delete children[i];
        }
    }
    
    void insert(const char *key){
        if(*key == '\0'){
            is_terminal=true;
        }
        else{
            int idx = char_to_idex(*key);
            if(children[idx]==0)
                children[idx] = new Trie();
            children[idx]->insert(key+1);
        }
    }
    
    bool find(const char *key){
        if(*key==0) return true;
        
        if(is_terminal) return false;
        
        int idx = char_to_idex(*key);
        return children[idx]->find(key+1);
    }
};
Trie *root;
int T,n;

bool CMP(string a, string b){
    return a.size() > b.size();
}
int main(){
    cin>>T;
    for(int t=0; t<T;t++){
        cin>>n;
        vector<string> input(n+1);
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        sort(input.begin(),input.end(),CMP);
        root = new Trie();
        for(int i=0; i<n;i++){
            root->insert(input[i].c_str());
        }
        
        bool answer = true;
        
        for(int i=0; i<n;i++){
            if(!root->find(input[i].c_str())){
                answer = false;
                break;
            }
        }
        cout<<(answer==true?"YES":"NO")<<endl;
    }
}
