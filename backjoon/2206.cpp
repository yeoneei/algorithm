//
//  2206.cpp
//  backjoon
//
//  Created by 조연희 on 30/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int n,m;
int map[1000][1000];
int check[2][1000][1000];

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

struct Node{
    int x,y, z;
    Node(int z, int y, int x):z(z),y(y),x(x){}
};
queue<Node> qu;

int bfs()
{
    while(!qu.empty()){
        int x = qu.front().x, y = qu.front().y, z=qu.front().z;
        qu.pop();
        if(y == n-1 && x == m-1) return check[z][y][x];
        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(map[ny][nx]==0 && check[z][ny][nx]==0){
                check[z][ny][nx] = check[z][y][x]+1;
                qu.push(Node(z,ny,nx));
            }
            if(map[ny][nx]==1 && check[z][ny][nx]==0 &&z==0){
                check[1][ny][nx] =check[z][y][x]+1;
                qu.push(Node(1,ny,nx));
            }
        }
        
    }
    return -1;
}

int main(){
    scanf("%d %d" ,&n, &m);
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    check[0][0][0]=1;
    qu.push(Node(0,0,0));
    int size =bfs();
    printf("%d",size);
}
