//
//  13460.cpp
//  backjoon
//
//  Created by 조연희 on 01/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
char map[10][10];
bool check[10][10][10][10];
struct Node{
    int rx;
    int ry;
    int bx;
    int by;
    Node(int rx, int ry, int bx, int by ):rx(rx),ry(ry),bx(bx),by(by){}
};

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool checkRead;
bool checkBlue;
queue<Node> qu;
int m,n;
int srx,sry,sbx,sby;
int main(){
    cin>>n>>m;
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
            if(map[i][j]=='R'){
                srx= j;
                sry= i;
            }
            if(map[i][j]=='B'){
                sbx=j;
                sby=i;
            }
        }
    }
    cout<<sry<<srx<<sby<<sbx<<endl;
    qu.push(Node(srx,sry,sbx,sby));
    
    int time=10;
    while(time--){
        int size = (int)qu.size();
        for(int i=0; i<size;i++){
            int nrx = qu.front().rx;
            int nry = qu.front().ry;
            int nbx = qu.front().bx;
            int nby = qu.front().by;
            qu.pop();
            for(int i=0;i<4;i++){
                int rc=0, rb=0;
                while(map[nry+dy[i]][nrx+dx[i]]!='#' && map[nry][nrx]!='O'){
                    nry +=dy[i];
                    nrx+=dx[i];
                    rc+=1;
                }
                while(map[nby+dy[i]][nbx+dx[i]]!='#' && map[nby][nbx]=='O'){
                    nby+=dy[i];
                    nrx+=dx[i];
                    rb+=1;
                }
                if(map[nby][nbx]=='O')continue;
                if(map[nry][nrx]=='O'){
                    cout<<10-time<<endl;
                    return 0;
                }
                if(nrx ==nbx && nry == nby){
                    if(rc>rb) {nrx-=dx[i]; nry-=dy[i];}
                    else {nbx-=dx[i]; nby-=dy[i];}
                }
                if (check[nrx][nry][nbx][nby]) continue;
                check[nrx][nry][nbx][nby] = true;
                qu.push(Node(nrx, nry, nbx, nby));
                
            }
        }
    }
    cout<<-1<<endl;
    
}
