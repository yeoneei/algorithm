//
//  1202.cpp
//  backjoon
//
//  Created by 조연희 on 09/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int n,k,v,m;
struct Node{
    int v;
    int m;
    double value;
    Node(int v, int m):v(v),m(m){
        value = (double)v / (double)m;
    }
};
struct NodeCmpt{
    bool operator()(Node n1, Node n2){
        if(n1.v < n2.v)return true;
        if(n1.v > n2.v)return false;
        if(n1.v == n2.v){
            if(n1.m < n2.m)return true;
            else return false;
        }
        return false;
    }
};
priority_queue<Node,vector<Node>,NodeCmpt> qu;
queue<int> back;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=0; i<n;i++){
        cin>>m>>v;
        qu.push(Node(v,m));
    }
    for(int i=0; i<k;i++){
        cin>>m;
        back.push(m);
    }
    long long answer=0;
    while(1){
        if(back.empty())break;
        if(qu.empty()) break;
        
        if(back.front() >= qu.top().m){
            answer += qu.top().v;
            back.pop();
        }
        qu.pop();
    }
    cout<<answer;
    
}
