//
//  1976.cpp
//  backjoon
//
//  Created by 조연희 on 02/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;


int n,temp,m;
int parent[201];

int find(int x){
    if(x==parent[x])return x;
    return parent[x]=find(parent[x]);
}

void uion(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x<y)parent[y]=x;
    else parent[x]=y;
}


int main(){
    cin>>n;
    for(int i=1; i<=n;i++){
        parent[i]=i;
    }
    cin>>m;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            cin>>temp;
            if(i<j && temp ==1){
                uion(i,j);
            }
        }
    }
    int root = -1;
    bool check=true;
    for(int i=0; i<m;i++){
        cin>>temp;
        if(root==-1){
            root = find(temp);
        }else{
            if(root != find(temp)){
                check= false;
            }
        }
    }
    
    if(check){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
}
