//
//  17144.cpp
//  backjoon
//
//  Created by 조연희 on 10/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;


int r,c,t;
int map[50][50];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

struct Node{
    int y;
    int x;
    Node(){}
    Node(int y, int x):y(y),x(x){}
};

Node air[2];
queue<Node> qu;
int airIdx=0;
int dif[50][50];



void getDuty(){
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            if(map[i][j]!=-1 && map[i][j]!=0){
                qu.push(Node(i,j));
            }
        }
    }
}
void diffusion(){
    memset(dif,0,sizeof(dif));
    while(!qu.empty()){
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();
        int cnt=0;
        for(int i=0; i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=r || nx<0 || nx>=c ||map[ny][nx]==-1)continue;
            dif[ny][nx]+= (map[y][x]/5);
            cnt++;
        }
        
        dif[y][x] += (map[y][x] - (map[y][x]/5)*cnt);
    }
    
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            if(map[i][j]!=-1){
                map[i][j]=dif[i][j];
            }
        }
    }
    
}



void airRotation(){
    int y = air[0].y;
    int x= air[0].x;
    x++;
    int t2;
    int t1=map[y][x];
    map[y][x]=0;
    for(int i=x+1; i<c;i++){
        t2 = map[y][i];
        map[y][i]=t1;
        t1 =t2;
    }
    
    for(int i=y-1; i>=0;i--){
        t2 = map[i][c-1];
        map[i][c-1]=t1;
        t1 =t2;
    }
    
    for(int i=c-2; i>=0;i--){
        t2 = map[0][i];
        map[0][i]=t1;
        t1 =t2;
    }
    for(int i=1; i<y;i++){
        t2 = map[i][0];
        map[i][0]=t1;
        t1 =t2;
    }
    y = air[1].y;
    x = air[0].x;
    x++;
    t1 = map[y][x];
    map[y][x]=0;
    
    for(int i=x+1; i<c;i++){
        t2 = map[y][i];
        map[y][i]=t1;
        t1 =t2;
    }
    
    for(int i=y+1; i<r;i++){
        t2 = map[i][c-1];
        map[i][c-1]=t1;
        t1 =t2;
    }
    
    for(int i=c-2; i>=0;i--){
        t2 = map[r-1][i];
        map[r-1][i]=t1;
        t1 =t2;
    }
    
    for(int i=r-2; i>y;i--){
        t2 = map[i][0];
        map[i][0]=t1;
        t1 =t2;
    }
    
}

int main(){
    cin>>r>>c>>t;
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cin>>map[i][j];
            if(map[i][j]==-1){
                air[airIdx].y =i;
                air[airIdx++].x=j;
            }
        }
    }
    while(t--){
        getDuty();
        diffusion();
        airRotation();
    }
    int sum=0;
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            sum+=map[i][j];
        }
    }
    cout<<sum+2;
    
    
    
}
