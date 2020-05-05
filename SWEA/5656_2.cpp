//
//  5656_2.cpp
//  backjoon
//
//  Created by 조연희 on 21/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int map[15][12];
int tempMap[15][12];
bool check[15][12];
int T;
int n,w,h;

int arr[4];
int answer=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


void copyMap(int (*a)[12], int(*b)[12]){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            b[i][j] = a[i][j];
        }
    }
}

queue<pair<int,int>> qu;
void go(int i, int j, int num){
    for(int s=0; s<4;s++){
        int time = num-1;
        int y = i;
        int x = j;
        while(time--){
            y+=dy[s];
            x+=dx[s];
            if(y<0 || y>=h || x<0 || x>=w)break;
            if(map[y][x]==0 ||check[y][x]==1)continue;
            if(map[y][x]!=1){
                qu.push(make_pair(y, x));
            }
            check[y][x]=1;
        }
    }
}
stack<int> st;
void relocate(){
    for(int i=0; i<w;i++){
        for(int j=0; j<h;j++){
            if(check[j][i]==1){
                map[j][i]=0;
                continue;
            }
            if(map[j][i]!=0)st.push(map[j][i]);
            map[j][i]=0;
        }
        int idx= h-1;
        while(!st.empty()){
            map[idx][i]=st.top();
            st.pop();
            idx--;
        }
    }
}
void printMap(){
    for(int i=0; i<h;i++){
        for(int j=0; j<w;j++){
            cout<<check[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    for(int i=0; i<h;i++){
        for(int j=0; j<w;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    
}

void push(int c){
    memset(check,0,sizeof(check));
    int idx =0;
    bool ch = false;
    while(idx<h){
        if(map[idx][c]!=0){
            ch=true;
            break;
        }
        idx++;
    }
    if(!ch)return;
    qu.push(make_pair(idx,c));
    while(!qu.empty()){
        check[qu.front().first][qu.front().second]=1;
        if(map[qu.front().first][qu.front().second]>1){
            go(qu.front().first,qu.front().second,map[qu.front().first][qu.front().second]);
        }
        qu.pop();
        
    }
    relocate();
    
}
void dfs(int cnt){
    if(cnt==n){
        int cnt=0;
        for(int i=0; i<h;i++){
            for(int j=0; j<w;j++){
                if(map[i][j]!=0)cnt++;
            }
        }
        answer = min(answer,cnt);
        return;
    }
    int temp[15][12];
    for(int y=0; y<h;y++){
        for(int x=0; x<w;x++){
            temp[y][x]=map[y][x];
        }
    }
    for(int i=0; i<w;i++){
        push(i);
        dfs(cnt+1);
        for(int y=0; y<h;y++){
            for(int x=0; x<w;x++){
                map[y][x]=temp[y][x];
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n>>w>>h;
        for(int i=0; i<h;i++){
            for(int j=0 ;j<w;j++){
                cin>>tempMap[i][j];
            }
        }
        answer=w*h;
        for(int y=0; y<h;y++){
            for(int x=0; x<w;x++){
                map[y][x]=tempMap[y][x];
            }
        }
        dfs(0);
        cout<<"#"<<tc<<" "<<answer<<'\n';
    }
}

