//
//  2573.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int map[300][300];
int cnt[10000];
bool check[300][300];
int n,m;

struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void printMap(){
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void printCh(){
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cout<<check[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

vector<Node> list;

bool zeroCheck(){
    for(int i=1; i<n-1;i++){
        for(int j=1; j<m-1;j++){
            if(map[i][j]!=0)return true;
        }
    }
    return false;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
            if(map[i][j]!=0){
                list.push_back(Node(i,j));
            }
            
        }
    }
    
    int t=0;
    while(zeroCheck()){
        t++;
        for(int i=0; i<list.size();i++){
            cnt[i]=0;
        }
        int idx=0;
        while(idx<list.size()){
            int y = list[idx].y;
            int x = list[idx].x;
            for(int d=0; d<4;d++){
                int ny= y + dy[d];
                int nx= x + dx[d];
                if(map[ny][nx]==0)cnt[idx]++;
            }
            idx++;
        }
        for(int i= list.size()-1;i>=0;i--){
            map[list[i].y][list[i].x]-=cnt[i];
            if(map[list[i].y][list[i].x]<=0){
                map[list[i].y][list[i].x]=0;
                list.erase(list.begin()+i);
            }
        }
        memset(check,0,sizeof(check));
        int ch=0;
        for(int i=0; i<list.size();i++){
            if(check[list[i].y][list[i].x]==0){
                check[list[i].y][list[i].x]=1;
                queue<Node> q;
                q.push(Node(list[i].y,list[i].x));
                while(!q.empty()){
                    int y = q.front().y;
                    int x = q.front().x;
                    q.pop();
                    for(int d=0; d<4;d++){
                        int ny= y+dy[d];
                        int nx= x+dx[d];
                        if(map[ny][nx]==0 || check[ny][nx]==1)continue;
                        check[ny][nx]=1;
                        q.push(Node(ny,nx));
                    
                    }
                }
                ch++;
            }
        }
        if(ch>=2){
            cout<<t;
            return 0;
        }
    }
    cout<<0;
    
}
