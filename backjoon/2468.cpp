//
//  2468.cpp
//  backjoon
//
//  Created by 조연희 on 23/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
int temp[100][100];
int n;
int lo=100,hi=0;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

struct Node{
    int x;
    int y;
    Node(int y, int x):y(y),x(x){}
};
void bfs(int y,int x){
    queue<Node> qu;
    qu.push(Node(y,x));
    while(!qu.empty()){
        int x = qu.front().x;
        int y = qu.front().y;
        qu.pop();
        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0|| nx>=n || ny<0 || ny>=n) continue;
            if(temp[ny][nx]==-1) continue;
            temp[ny][nx]=-1;
            qu.push(Node(ny,nx));
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
            lo = min(map[i][j],lo);
            hi = max(map[i][j],hi);
            
        }
    }
    
    int mV=1;
    for(int cri = lo ; cri<=hi;cri++){
        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                if(map[i][j]<=cri)
                    temp[i][j]=-1;
                else temp[i][j]=map[i][j];
            }
        }
        int cnt=0;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if(temp[i][j]>=lo){
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        mV = max(mV, cnt);
    }
    cout<<mV<<endl;

}
