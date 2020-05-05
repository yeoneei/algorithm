//
//  섬연결하기.cpp
//  backjoon
//
//  Created by 조연희 on 18/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <queue>
#include <iostream>
using namespace std;

struct Node{
    int v1;
    int v2;
    int c;
    Node(int v1, int v2, int c):v1(v1),v2(v2),c(c){}
};
struct NodeCmp{
    bool operator()(Node n1, Node n2){
        if(n1.c > n2.c){
            return true;
        }else{
            return false;
        }
    }
};
priority_queue<Node, vector<Node>,NodeCmp> pq;
void init(){
    if(!pq.empty()){
        pq.pop();
    }
}
int parent[100];
int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
}

bool uion_find(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return false;
    parent[x] = y;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    init();
    for(int i=0; i<n;i++){
        parent[i]=i;
    }
    for(int i=0; i<costs.size();i++){
        pq.push(Node(costs[i][0],costs[i][1],costs[i][2]));
    }
    int answer = 0;
    int t=0;
    while(!pq.empty()){
        if(t==n-1){
            break;
        }
        int v1 = pq.top().v1;
        int v2 = pq.top().v2;
        int c = pq.top().c;
       
        if(!uion_find(v1,v2)){
            pq.pop();
            continue;
        }
        answer+=c;
        t++;
        pq.pop();
    }
    return answer;
}

int main(){
    vector<vector<int>> cost;
    vector<int> in;
    in.push_back(0);
    in.push_back(1);
    in.push_back(1);
    cost.push_back(in);
    in.clear();
    in.push_back(0);
    in.push_back(2);
    in.push_back(2);
    cost.push_back(in);
    in.clear();
    in.push_back(1);
    in.push_back(2);
    in.push_back(5);
    cost.push_back(in);
    in.clear();
    in.push_back(1);
    in.push_back(3);
    in.push_back(1);
    cost.push_back(in);
    in.clear();
    in.push_back(2);
    in.push_back(3);
    in.push_back(8);
    cost.push_back(in);
    in.clear();
    cout<<solution(4, cost)<<endl;
    
}
