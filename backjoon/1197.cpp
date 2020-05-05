//
//  1197.cpp
//  backjoon
//
//  Created by 조연희 on 20/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;


struct Node{
    int s;
    int d;
    int c;
    Node(int s, int d, int c):s(s),d(d),c(c){}
};
struct NodeCmp{
    bool operator()(Node n1, Node n2){
        return n1.c > n2.c;
    }
};

priority_queue<Node, vector<Node>, NodeCmp> pq;
int n,m,a,b,c;
int parent[10001];

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool union_find(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return true;
    parent[y]=x;
    return false;
}


int main(){
    cin>>n>>m;
    for(int i=0; i<m;i++){
        cin>>a>>b>>c;
        pq.push(Node(a,b,c));
    }
    
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    int t=0;
    int answer=0;
    
    while(!pq.empty()){
        if(t==n-1){
            break;
        }
        if(!union_find(pq.top().s, pq.top().d)){
            t++;
            answer+=pq.top().c;
        }
        pq.pop();
    }
    cout<<answer<<endl;
}
