//
//  17147.cpp
//  backjoon
//
//  Created by 조연희 on 27/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 50
using namespace std;

int n,m;
struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};
int a;
int map[MAX+1][MAX+1];
vector<Node> active;
bool germCheck[MAX+1];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int answerT=10000;
void dfs(int cnt,int v,vector<int> number){
    if(cnt==m){
        queue<Node> qu;
        int allCheck[MAX+1][MAX+1];
        memset(allCheck, -1, sizeof(allCheck));
        
        for(int i=0; i<number.size();i++){
            qu.push(Node(active[number[i]].y,active[number[i]].x));
            allCheck[active[number[i]].y][active[number[i]].x]=0;
        }
        int t=0;
        int ans=0;
        while(!qu.empty()){
            int y = qu.front().y;
            int x= qu.front().x;
            qu.pop();
            for(int i=0; i<4;i++){
                int ny = y + dy[i];
                int nx = x +dx[i];
                if(ny<0 || ny>=n || nx<0 || nx>=n || allCheck[ny][nx]!=-1 ||map[ny][nx]==1)continue;
                allCheck[ny][nx]=allCheck[y][x]+1;
                if(map[ny][nx]==0){
                    t=allCheck[ny][nx];
                    ans++;
                }
                qu.push(Node(ny,nx));
            }
        }
        bool check = true;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(map[i][j]==0 && allCheck[i][j]==-1){
                    check= false;
                    break;
                }
            }
        }
        
        if(check) answerT = min(t, answerT);
        return;
        
    }
    for(int i=v;i<active.size();i++){
        if(germCheck[i])continue;
        germCheck[i]=1;
        number.push_back(i);
        dfs(cnt+1,i,number);
        number.pop_back();
        germCheck[i]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                active.push_back(Node(i,j));
            }
            if(map[i][j]==0){
                a++;
            }
        }
    }
    vector<int> temp;
    dfs(0,0,temp);
    if(answerT==10000){
        cout<<-1;
    }else{
        cout<<answerT;
    }
}

