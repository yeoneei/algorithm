//
//  7576.cpp
//  backjoon
//
//  Created by 조연희 on 11/04/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int tomato[1000][1000]={0,};
int width,hegiht;
typedef pair<int,int> P;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};


int bfs(queue<P> &one){
    int max=0;
    while(!one.empty()){
        P temp = one.front();
        one.pop();
        for(int i=0;i<4;i++){
            int x = temp.second+dx[i];
            int y = temp.first+dy[i];
            if(0<=x && x<width && 0<= y && y<hegiht && tomato[y][x]==0){
                tomato[y][x]= tomato[temp.first][temp.second]+1;
                if(max < tomato[y][x]){
                    max = tomato[y][x];
                }
                one.push(P(y,x));
                
            }
        }
    }
    return max-1;
}

bool allCheck(int tomato[][1000]){
    bool all = true;
    for(int i=0; i<hegiht;i++){
        for(int j=0; j<width;j++){
            if(tomato[i][j]==-1){
                continue;
            }else if(tomato[i][j]==0){
                all= false;
                break;
            }
        }
    }
    return all;
}

int main(){
    cin>>width>>hegiht;
    queue<P> one;
    for(int i=0; i<hegiht;i++){
        for(int j=0; j<width;j++){
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j]==1){
                one.push(P(i,j));
            }
        }
    }
    bool check = allCheck(tomato);
    if(check){
        cout<<0;
        return 0;
    }
    
    int max = bfs(one);
    check = allCheck(tomato);
    if(check){
        cout<<max;
    }else{
        cout<<-1;
    }
    
}

