//
//  16236.cpp
//  backjoon
//
//  Created by 조연희 on 04/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;


int n;
int map[20][20];
struct Node{
    int y;
    int x;
    int size;
    Node(){}
    Node(int y, int x, int size):y(y),x(x),size(size){}
};

Node ba;
vector<Node> fish;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool check[20][20];
int dist(int sy, int sx){
    memset(check,0,sizeof(check));
    queue<Node> qu;
    check[ba.y][ba.x]=1;
    qu.push(Node(ba.y,ba.x,0));
    while(!qu.empty()){
        int y = qu.front().y;
        int x= qu.front().x;
        int d = qu.front().size;
        qu.pop();
        if(sy==y && sx==x){
            return d;
        }
        for(int i=0; i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n || map[ny][nx]>ba.size|| check[ny][nx])continue;
            check[ny][nx]=1;
            qu.push(Node(ny,nx,d+1));
        }
    }
    return 0;
}

bool Cmp(Node f1, Node f2){
    if(f1.size <f2.size)return true;
    else if(f1.size > f2.size)return false;
    else if(f1.y <f2.y)return true;
    else if(f1.y > f2.y) return false;
    else if(f1.x < f2.x)return true;
    return false;
}


void getFish(){
    fish.clear();
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(map[i][j]!=0 && map[i][j]!=9 && map[i][j]<ba.size){
                fish.push_back(Node(i,j,dist(i, j)));
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==9){
                ba.y= i;
                ba.x=j;
                ba.size = 2;
            }
        }
    }
    getFish();
    int t=0;
    int cnt=0;
    while(fish.size()!=0){
        sort(fish.begin(),fish.end(),Cmp);
        int idx =-1;
        for(int i=0; i<fish.size();i++){
            if(fish[i].size>0){
                idx =i;
                break;
            }
        }
        if(idx==-1)break;
        t+=fish[idx].size;
        map[ba.y][ba.x]=0;
        ba.y= fish[idx].y;
        ba.x= fish[idx].x;
        cnt++;
        if(cnt==ba.size){
            ba.size=ba.size+1;
            cnt=0;
        }
        map[fish[idx].y][fish[idx].x]=9;
        getFish();
        
    }
    cout<<t;
}
