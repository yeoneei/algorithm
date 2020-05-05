//
//  44.cpp
//  backjoon
//
//  Created by 조연희 on 25/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>>vc;


void insertMa(int col, int color){
    int idx=5;
    while(1){
        if(vc[idx][col]==0){
            vc[idx][col]=color;
            break;
        }
        idx--;
    }
}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check[6][6];
int dfs(int y, int x, int ch){
    int ret =1;
    for(int i=0; i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=6 || nx<0 || nx>=6 ||check[ny][nx])continue;
        if(vc[ny][nx]==ch){
            check[ny][nx]=1;
            ret +=dfs(ny,nx,ch);
        }
    }
    return ret;
}

void remove(int y, int x, int ch){
    for(int i=0; i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=6 || nx<0 || nx>=6 )continue;
        if(vc[ny][nx]==ch){
            vc[ny][nx]=0;
            remove(ny,nx,ch);
        }
    }
    
}

void rechangeBoard(int i, int j, int color){
    stack<int> st;
    for(int x=0; x<6;x++){
        for(int y=0; y<6;y++){
            if(vc[y][x]==0)continue;
            st.push(vc[y][x]);
            vc[y][x]=0;
        }
        for(int y=5;y>=0;y--){
            if(!st.empty()){
                vc[y][x]=st.top();
                st.pop();
            }else break;
        }
    }
}

queue<pair<int,int>> qu;
bool endCheck(){
    memset(check,0,sizeof(check));
    for(int i=0; i<6;i++){
        for(int j=0; j<6;j++){
            if(vc[i][j]==0 || check[i][j]==1)continue;
            check[i][j]=1;
            int cnt = dfs(i,j,vc[i][j]);
            if(cnt>=3){
                qu.push(make_pair(i,j));
            }
        }
    }
    
    if(qu.empty())return false;
    return true;
}


vector<string> solution(vector<vector<int>> macaron) {
    vc.clear();
    vc.resize(6);
    vector<string> answer;
    for(int i=0; i<6;i++){
        vc[i].resize(6);
    }
    for(int i=0; i<macaron.size();i++){
        insertMa(macaron[i][0]-1,macaron[i][1]);
        if(endCheck()){
            while(!qu.empty()){
                remove(qu.front().first,qu.front().second,vc[qu.front().first][qu.front().second]);
                rechangeBoard(qu.front().first, qu.front().second, vc[qu.front().first][qu.front().second]);
                qu.pop();
                
            }
        }
        
    }
    
    while(endCheck()){
        while(!qu.empty()){
            remove(qu.front().first,qu.front().second,vc[qu.front().first][qu.front().second]);
            rechangeBoard(qu.front().first, qu.front().second, vc[qu.front().first][qu.front().second]);
            qu.pop();
            
        }
    }
    for(int i=0; i<6;i++){
        string temp="";
        for(int j=0; j<6;j++){
            temp+=to_string(vc[i][j]);
        }
        answer.push_back(temp);
    }
    
    
    return answer;
}

int main(){
    vector<vector<int>> mar = {{1,1},{2,1},{1,2},{3,3},{6,4},{3,1},{3,3},{3,3},{3,4},{2,1}};
    solution(mar);
}
