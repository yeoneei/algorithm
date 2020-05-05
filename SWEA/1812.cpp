//
//  1812.cpp
//  backjoon
//
//  Created by 조연희 on 29/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int y;
    int x;
    Node(int y, int x):y(y<=x?y:x),x(y<=x?x:y){}
};
struct CMP{
    bool operator()(Node n1, Node n2){
        return n1.y < n2.y;
    }
};

int T,n,m,temp;
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n>>m;
        priority_queue<Node, vector<Node>,CMP>pq;
        priority_queue<int> list;
        for(int i=0; i<n;i++){
            cin>>temp;
            list.push((1<<temp));
        }
        int cnt=1;
        pq.push(Node(m,m));
        while(!list.empty()){
            int y = pq.top().y;
            int k = list.top();
            list.pop();
            if(pq.empty() || y<k){
                cnt++;
                if(k!=m){
                    pq.push(Node(m-k,m));
                    pq.push(Node(m-k,k));
                }
            }else{
                int x= pq.top().x;
                pq.pop();
                if(k==y){
                    pq.push(Node(y,x-y));
                }else{
                    pq.push(Node(x-k,y));
                    pq.push(Node(y-k,k));
                }
            }
        }
        cout<<"#"<<tc<<" "<<cnt<<endl;
    }
}
