//
//  1824.cpp
//  backjoon
//
//  Created by 조연희 on 24/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MAX 21
using namespace std;

char map[MAX][MAX];
bool check[MAX][MAX][4][16];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int T,n,m;
bool endLoop=false;
void dfs(int curX, int curY, int dir, int mem){
    while(!endLoop){
        
        if(check[curY][curX][dir][mem]==true){
            return;
        }
        char temp = map[curY][curX];
        check[curY][curX][dir][mem]=true;
        if(temp=='<') dir = 1;
        else if(temp=='>') dir=0;
        else if(temp=='v') dir=2;
        else if(temp=='^') dir=3;
        else if(temp=='+') mem = (mem==15?0:mem+1);
        else if(temp=='-') mem = (mem==0?15:mem-1);
        else if(temp=='@') {
            endLoop=true;
            return;
        }else if('0'<=temp && temp<='9') mem = temp-'0';
        else if(temp=='_') dir = (mem==0?0:1);
        else if(temp=='|') dir = (mem==0? 2:3);
        else if(temp=='?'){
            for(int i=0; i<4;i++){
                int nx = curX+dx[i];
                int ny = curY+dy[i];
                nx = (nx==m?0:nx);
                nx = (nx<0?m-1:nx);
                ny = ny==n?0:ny;
                ny = ny<0?n-1:ny;
                if(!check[ny][nx][i][mem]){
                    dfs(nx,ny,i,mem);
                }
                
            }
            return;
        }
        curX+=dx[dir];
        curY+=dy[dir];
        curX = curX==m?0:curX;
        curX = curX<0?m-1:curX;
        curY = curY==n?0:curY;
        curY = curY<0?n-1:curY;
        
    }
}
int main(){
    scanf("%d", &T);
    for(int t=1; t<=T;t++){
        endLoop=false;
        scanf("%d %d",&n,&m);
        memset(check,false,sizeof(check));
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&map[i][j]);
            }
        }
        dfs(0,0,0,0);
        printf("#%d ",t);
        if(endLoop){
            printf("YES \n");
        }else {
            printf("NO \n");
        }
    }
}
