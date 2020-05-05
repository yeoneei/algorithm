//
//  17619.cpp
//  backjoon
//
//  Created by 조연희 on 04/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#define MAX 100000
using namespace std;

int n,m,x1,x2,y,fi,se;
int parent[MAX];
struct Node{
    int y;
    int x1;
    int x2;
    Node(int y,int x1, int x2):y(y),x1(x1),x2(x2){}
};

bool Cmp(Node n1, Node n2){
    return n1.x1 < n2.x1;
}

int find(int x){
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x]);
}

void uion(int y, int x){
    y = find(y);
    x = find(x);
    if(y>x)parent[y]=x;
    else parent[x]=y;
}
vector<Node> node;
map<string,int> mm;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<MAX;i++){
        parent[i]=i;
    }
    for(int i=0; i<n;i++){
        cin>>x1>>x2>>y;
        node.push_back(Node(y,x1,x2));
        string temp = to_string(y)+to_string(x1)+to_string(x2);
        mm[temp]=i;
    }
    sort(node.begin(),node.end(),Cmp);
    
    string temp = to_string(node[0].y)+to_string(node[0].x1)+to_string(node[0].x2);
    int base = node[0].x2;
    int lastIdx = mm[temp];
    for(int i=1; i<node.size();i++){
        string temp = to_string(node[i].y)+to_string(node[i].x1)+to_string(node[i].x2);
        if(node[i].x1<=base){
            uion(lastIdx,mm[temp]);
            lastIdx = mm[temp];
            base = max(base, node[i].x2);
        }else{
            lastIdx = mm[temp];
            base = node[i].x2;
        }
    }
    for(int i=0;i<m;i++){
        cin>>fi>>se;
        if(find(fi-1)==find(se-1)){
            cout<<1<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
    
}
