//
//  1707.cpp
//  backjoon
//
//  Created by 조연희 on 24/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


int check[200001];
vector<vector<int>> vc;
int T,n,m,t1,t2;
bool biartie=true;
void dfs(int status,int v){
    if(!biartie){
        return;
    }
    for(auto i : vc[v]){
        if(check[i]!=0){
            if(check[i]%2 == check[v]%2){
                biartie = false;
                return;
            }else{
                continue;
            }
        }
        check[i]= status+1;
        dfs(status+1,i);
    }
}

int main(){
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n>>m;
        vc.clear();
        vc.resize(n+1);
        biartie = true;
        memset(check, 0, sizeof(check));
       
        for(int i=0; i<m;i++){
            cin>>t1>>t2;
            vc[t1].push_back(t2);
            vc[t2].push_back(t1);
        }
        
        for(int i=1; i<=n;i++){
            if(check[i]!=0) continue;
            check[i]=1;
            dfs(1,i);
        }
        
        if(biartie){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
        
    }
}
