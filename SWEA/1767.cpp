//
//  1767.cpp
//  backjoon
//
//  Created by 조연희 on 25/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stdio.h>
#define MAX 12
using namespace std;

int map[MAX][MAX];
int T,n;
struct Node{
    int y;
    int x;
    Node(int y,int x):y(y),x(x){};
};
struct Result{
    int c;
    int r;
    Result(int c, int r):c(c),r(r){};
};
struct cmp{
    bool operator()(Result t1, Result t2){
        if(t1.c < t2.c){
            return true;
        }else if(t1.c > t2.c){
            return false;
        }else {
            if(t1.r > t2.r){
                return true;
            }else{
                return false;
            }
        }
    }
};

queue<Node> qu;
priority_queue<Result, vector<Result>,cmp> pq;


int maxScore=1000;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int checkScore(int map[][MAX]){
    int result = 0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(map[i][j]==1){
                result++;
            }
        }
    }
    cout<<"result" <<result<<endl;
    return result-n;
}

void dfs(queue<Node> qu, int map[][MAX]){
    if(qu.empty()){
        return;
    }
    
    
    int copy[MAX][MAX];
    int y = qu.front().y;
    int x = qu.front().x;
    qu.pop();
    printf("%d %d \n",y,x);

    for(int i=0; i<4;i++){
        for(int j = 0; j<n;j++){
            for(int k =0; k<n;k++){
                copy[j][k]=map[j][k];
                printf("%d ",copy[j][k]);
            }
            printf("\n");
        }
        printf("\n");
        int ny = y;
        int nx = x;
        bool checkS=true;
        while(1){
            nx+=dx[i];
            ny+=dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>n){
                break;
            }
            if(copy[ny][nx]==1){
                checkS = false;
                break;
            }
            copy[ny][nx]=1;
        }
        
        if(checkS){
            pq.push(Result((n-(int)qu.size()),checkScore(copy)));
            dfs(qu, copy);
        }
    }
}

int main(){
    freopen("/Users/yeoni/Desktop/test/backjoon/SWEA/1767_input.txt", "r", stdin);
    scanf("%d",&T);
    for(int t=1; t<=T;t++){
        scanf("%d",&n);
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                scanf("%d", &map[i][j]);
                if(map[i][j]==1){
                    if(i==0 || j==0 || i==n-1 || j==n-1){
                        map[i][j]=1;
                    }else{
                        qu.push(Node(i,j));
                        map[i][j]=1;
                    }
                }
            }
        }
        dfs(qu,map);
        printf("#%d %d\n",t,pq.top().r);
        while(!pq.empty()){
            printf("%d %d\n",pq.top().c,pq.top().r);
            pq.pop();
        }
       
        
    }
}
