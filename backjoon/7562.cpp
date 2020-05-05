//
//  7562.cpp
//  backjoon
//
//  Created by 조연희 on 24/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int T;
int n,sx,sy,dex,dey;
struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){};
};

int dx[8]={-1,-2,1,2,-2,-1,1,2};
int dy[8]={-2,-1,-2,-1,1,2,2,1};
bool map[301][301];

int main(){
    cin>>T;
    for(int t=1; t<=T;t++){
        cin>>n;
        cin>>sx>>sy;
        cin>>dex>>dey;
        memset(map,0,sizeof(map));
        queue<Node> qu;
        qu.push(Node(sy,sx));
        int time=0;
        bool lastCheck=false;
        while(!qu.empty()){
            if(lastCheck==true){
                break;
            }
            int size =(int)qu.size();
            time++;
            for(int i=0; i<size;i++){
                if(dex == qu.front().x && dey == qu.front().y){
                    lastCheck=true;
                    break;
                }
                int y = qu.front().y;
                int x = qu.front().x;
                qu.pop();
                for(int i=0; i<8;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<0 || nx>=n || ny<0 ||ny>=n)continue;
                    if(map[ny][nx]) continue;
                    map[ny][nx]=1;
                    qu.push(Node(ny,nx));
                }
            }
        }
        cout<<time-1<<endl;
    }
}
