//
//  1824.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int T,n,m;
char map[20][20];
int check[16][20][20];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int endX;
int endY;

struct Node{
    int y;
    int x;
    int mem;
    int d;
    Node(int y,int x, int mem,int d):y(y),x(x),mem(mem),d(d){}
};

int main(){
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        cin>>n>>m;
        memset(check,0,sizeof(check));
        endX=-1;
        endY=-1;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                cin>>map[i][j];
                if(map[i][j]=='@'){
                    endY=i;
                    endX=j;
                }
            }
        }
        bool ans=false;
        queue<Node> qu;
        qu.push(Node(0,0,0,0));

        while(!qu.empty()){
            int y = qu.front().y;
            int x = qu.front().x;
            int d = qu.front().d;
            int mem = qu.front().mem;
            qu.pop();
            
            cout<<map[y][x]<<" "<<mem<<endl;
            if(map[y][x]=='<')d=1;
            else if(map[y][x]=='>')d=0;
            else if(map[y][x]=='^')d=3;
            else if(map[y][x]=='v')d=2;
            else if(map[y][x]=='_'){
                if(mem==0)d=0;
                else d=1;
            }else if(map[y][x]=='|'){
                if(mem==0)d=2;
                else d=3;
            }else if(map[y][x]=='@'){
                ans = true;
                break;
            }else if(map[y][x]=='+'){
                mem++;
                if(mem>15)mem=0;;
            }else if(map[y][x]=='-'){
                mem--;
                if(mem<0)mem=15;
            }else if(map[y][x]>='0' && map[y][x]<='9'){
                mem = (int)(map[y][x]-'0');
            }else if(map[y][x]=='?'){
                for(int i=0; i<4;i++){
                    if((check[mem][y][x]&(1<<i)) == (1<<i)){
                        continue;
                    }
                    check[mem][y][x]+=(1<<i);
                    int ny = y+dy[i];
                    int nx = x+dx[i];
                    if(nx<0 || nx>=m || ny<0 || ny>=n){
                        nx = nx<0?nx+m:nx;
                        nx = nx>=m?nx-m:nx;
                        ny = ny<0?ny+n:ny;
                        ny = ny>=n?ny-n:ny;
                    }
                    qu.push(Node(ny,nx,mem,i));
                }
                continue;
            }
            
            if((check[mem][y][x]&(1<<d)) == (1<<d)){
                continue;
            }
            
            check[mem][y][x]+=(1<<d);
            y +=dy[d];
            x +=dx[d];
            if(x<0 || x>=m || y<0 || y>=n){
                x = x<0?x+m:x;
                x = x>=m?x-m:x;
                y = y<0?y+n:y;
                y = y>=n?y-n:y;
            }
            qu.push(Node(y,x,mem,d));
        }
        
        cout<<"#"<<tc<<" ";
        if(ans){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }
}
