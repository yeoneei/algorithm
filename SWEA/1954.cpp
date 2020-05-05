//
//  1954.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
int map[10][10];
int T,n;

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int ny=0;
int nx=0;
int idx=1;
int d=0;
void changeDir(){
    ny-=dy[d];
    nx-=dx[d];
    d++;
    if(d==4)d=0;
    ny+=dy[d];
    nx+=dx[d];
}

void printMap(){
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        int time = n*n;
        memset(map,0,sizeof(map));
        ny=0;
        nx=0;
        idx=1;
        d=0;
        while(time--){
            map[ny][nx]=idx++;
            ny+=dy[d];
            nx+=dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=n || map[ny][nx]!=0){
                changeDir();
            }
        }
        cout<<'#'<<tc<<'\n';
        printMap();
    }
}
