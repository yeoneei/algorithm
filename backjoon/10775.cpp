//
//  10775.cpp
//  backjoon
//
//  Created by 조연희 on 04/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int G,P,temp;
int parent[100001];
int find(int x){
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x]);
}

void uion(int y, int x){
    y = find(y);
    x = find(x);
    
    if(y > x)parent[y]=x;
    else parent[x]=y;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>G;
    for(int i=0; i<=G;i++){
        parent[i]=i;
    }
    cin>>P;
    int cnt=0;
    for(int i=1; i<=P;i++){
        cin>>temp;
        int doc = find(temp);
        if(doc!=0){
            uion(doc-1, doc);
            cnt++;
        }else{
            break;
        }
        
    }
    cout<<cnt;
}
