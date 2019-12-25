//
//  1767.cpp
//  backjoon
//
//  Created by 조연희 on 25/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stdio.h>
#define MAX 13
using namespace std;
int T,n;
bool map[MAX][MAX];
struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};
struct Cmp{
    bool operator()(Node n1, Node n2){
        if(n1.y < n2.y){
            return true;
        }else if(n1.y > n2.y){
            return false;
        }else{
            if(n1.x > n2.x){
                return true;
            }else{
                return false;
            }
        }
    }
};

queue<Node> qu;
priority_queue<Node, vector<Node>,Cmp> pq;

int checkScore(bool map[][MAX]){
    int result=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(map[i][j]){
                result++;
            }
        }
    }
    return result-n;
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(queue<Node> qu, bool map[][MAX]){
    if(qu.empty()){
        return;
    }
    
    int y = qu.front().y;
    int x = qu.front().x;
    qu.pop();
    bool copy[MAX][MAX];
    for(int i=0; i<4;i++){
        for(int j=0; j<n;j++){
            for(int k=0; k<n;k++){
                copy[j][k]=map[j][k];
            }
        }
        int ny = y;
        int nx = x;
        bool check = true;
        while(1){
            ny+=dy[i];
            nx+=dx[i];
            if(ny<0 || ny>=n ||nx<0 || nx>=n){
                break;
            }
            if(copy[ny][nx]){
                check = false;
                break;
            }
            copy[ny][nx]=1;
        }
        
        if(check){
            pq.push(Node(n-(int)qu.size(),checkScore(copy)));
            dfs(qu,copy);
        }
    }
}

void init(){
    while(!qu.empty()){
        qu.pop();
    }
    while(!pq.empty()){
        pq.pop();
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int t=1; t<=T;t++){
        cin>>n;
        init();
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>map[i][j];
                if(map[i][j]){
                    if(i!=0 || j!=0 || i!=n-1 || j!=n-1){
                        qu.push(Node(i,j));
                    }
                }
            }
        }
        
        dfs(qu,map);
        printf("#%d %d \n",t,pq.top().x);
        
    }
    
}
