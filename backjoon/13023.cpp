//
//  13023.cpp
//  backjoon
//
//  Created by 조연희 on 24/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n,m,t1,t2;
vector<vector<int>> vc;
bool answerCheck = false;
bool check[2001];
void dfs(int cnt, int v){
    if(cnt==4){
        answerCheck=true;
        return ;
    }
    for(auto i : vc[v]){
        if(check[i]) continue;
        check[i]=true;
        dfs(cnt+1, i);
        check[i]=false;
    }
    
    
}

int main(){
    cin>>n>>m;
    vc.resize(n+1);
    for(int i=0; i<m;i++){
        cin>>t1>>t2;
        vc[t1].push_back(t2);
        vc[t2].push_back(t1);
    }
    
    for(int i=0; i<n;i++){
        if(answerCheck == true){
            break;
        }
        memset(check, 0, sizeof(check));
        check[i]=1;
        dfs(0,i);
    }
    cout<<answerCheck<<endl;
    
}
