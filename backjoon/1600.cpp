//
//  1600.cpp
//  backjoon
//
//  Created by 조연희 on 31/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int x,y,z;
    Node(int z, int y, int x):z(z),y(y),x(x){}
};

queue<Node> qu;
int dist[31][201][201];
bool map[201][201];
int k,n,m;
int dx[12]={0,0,1,-1,1,-1,-2,-2,-1,1,2,2};
int dy[12]={1,-1,0,0,2,2,1,-1,-2,-2,-1,1};

int bfs(){
    int size =0;
    while(!qu.empty()){
        int x = qu.front().x ,y= qu.front().y, z = qu.front().z;
        qu.pop();
        if(z<=k-1) size = 12;
        else size =4;
        
        if(x == m-1 && y == n-1) return dist[z][y][x];
        for(int i=0; i<size;i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            
            if(map[ny][nx]==0  && i<4 && dist[z][ny][nx]==0){
                dist[z][ny][nx]= dist[z][y][x]+1;
                qu.push(Node(z,ny,nx));
            }
            
            if(i>=4 && map[ny][nx]==0 && dist[z+1][ny][nx]==0){
                dist[z+1][ny][nx]= dist[z][y][x]+1;
                qu.push(Node(z+1,ny,nx));
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d",&k);
    scanf("%d %d",&m, &n);
    
    for(int i=0; i<n;i++){
        for(int j=0 ; j<m;j++){
            cin>>map[i][j];
        }
    }
    dist[0][0][0]=0;
    qu.push(Node(0,0,0));
    printf("%d",bfs());
    
}
