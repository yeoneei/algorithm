//
//  1.cpp
//  CodingTest
//
//  Created by 조연희 on 11/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int x;
    int y;
    Node(int x, int y):x(x),y(y){}
};

queue<Node> v;
int n,l,r,b,t;
int x, y;
int main(){
    cin>>n>>l>>r>>b>>t;
    
    for(int i=0; i<n;i++){
        cin>>x>>y;
        v.push(Node(x,y));
    }
    
    int cnt=0;
    while(!v.empty()){
        int x = v.front().x;
        int y = v.front().y;
        v.pop();
        if(l<= x && x<=r && b <=y && y<=t){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
