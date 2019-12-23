//
//  2178.cpp
//  backjoon
//
//  Created by 조연희 on 29/05/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int map [101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int Y, X;
int minSize = 1000;

void dfs(int y, int x, int size){
    if(Y ==y && X==x){
        if(minSize>size){
            minSize= size;
        }
    }else{
        map[y][x] = -1;
        for(int i=0; i<4;i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(1<= newX && newX<=X && 1<=newY && newY <=Y && minSize>size){
                if(map[newY][newX]==1){
                    dfs(newY,newX,size+1);
                }
            }
        }
        map[y][x]=1;
    }
}

int main(){
    scanf("%d %d",&Y,&X);
    for(int i=1; i<=Y;i++){
        for(int j=1; j<=X;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    dfs(1,1,0);
    printf("%d",minSize+1);
}

