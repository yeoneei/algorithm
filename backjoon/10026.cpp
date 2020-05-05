//
//  10026.cpp
//  backjoon
//
//  Created by 조연희 on 02/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

char map[100][100];
bool check[100][100];
int arr[3];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

struct Node{
    int y;
    int x;
    Node(int y,int x):y(y),x(x){}
};

int n;
void bfs(int sy, int sx){
    queue<Node> qu;
    qu.push(Node(sy,sx));
    if(map[sy][sx]=='R'){
        arr[0]++;
    }else if(map[sy][sx]=='G'){
        arr[1]++;
    }else arr[2]++;
    
    char color = map[sy][sx];
    check[sy][sx]=1;
    while(!qu.empty()){
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();
        for(int i=0; i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n || check[ny][nx] || map[ny][nx]!=color)continue;
            check[ny][nx]=1;
            qu.push(Node(ny,nx));
        }
    }
}

void bfs2(int sy, int sx){
    queue<Node> qu;
    qu.push(Node(sy,sx));
    check[sy][sx]=1;
    while(!qu.empty()){
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();
        for(int i=0; i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n || check[ny][nx] || map[ny][nx]=='B')continue;
            check[ny][nx]=1;
            qu.push(Node(ny,nx));
        }
    }
}


int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
        }
    }
    
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(check[i][j])continue;
            bfs(i,j);
        }
    }
    
    cout<<arr[0]+arr[1]+arr[2]<<" ";
    memset(check,0,sizeof(check));
    arr[0]=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(check[i][j] || map[i][j]=='B')continue;
            arr[0]++;
            bfs2(i,j);
        }
    }
    cout<<arr[0]+arr[2]<<endl;
}
