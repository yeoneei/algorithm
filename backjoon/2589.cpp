
//
//  2589.cpp
//  backjoon
//
//  Created by 조연희 on 24/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n,m;
vector<string> map;
int de[50][50];
bool check[50][50];

int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};
int mV =0;
void bfs(int y, int x){
    queue<Node> qu;
    qu.push(Node(y,x));
    check[y][x]=1;
    while(!qu.empty()){
        int x = qu.front().x;
        int y = qu.front().y;
        qu.pop();
        for(int i=0; i<4;i++){
            int nx = x+ dx[i];
            int ny = y +dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(map[ny][nx]!='L' || check[ny][nx]==1) continue;
            check[ny][nx]=1;
            de[ny][nx]=de[y][x]+1;
            mV = max(mV, de[ny][nx]);
            qu.push(Node(ny,nx));
        }
        
    }
}

void init(){
    memset(de,0,sizeof(de));
    memset(check,0,sizeof(check));
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        string a;
        cin>>a;
        map.push_back(a);
    }
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(map[i][j]=='L'){
                init();
                bfs(i,j);
            }
        }
    }
    
    cout<<mV<<endl;
}
