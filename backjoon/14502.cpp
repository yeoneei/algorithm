//
//  14502.cpp
//  backjoon
//
//  Created by 조연희 on 23/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mapOri[8][8];
int map[8][8];
bool check[64];
int n,m;
vector<vector<int>> v;
void pick(int cnt, vector<int> temp){
    if(cnt==3){
        v.push_back(temp);
        return;
    }
    if(cnt>=3) return;
    
    for(int i=0; i<n*m;i++){
        if(check[i]==1) continue;
        check[i]=1;
        temp.push_back(i);
        pick(cnt+1,temp);
        check[i]=0;
        temp.pop_back();
    }
}


struct Node{
    int x;
    int y;
    Node(int y, int x):x(x),y(y){}
};

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void findArea(queue<Node> qu){
    while(!qu.empty()){
        int x = qu.front().x;
        int y = qu.front().y;
        qu.pop();
        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(map[ny][nx]!=0) continue;
            map[ny][nx] =2;
            qu.push(Node(ny,nx));
            
        }
    }
}

int main(){
    cin>>n>>m;
    queue<Node> q;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>mapOri[i][j];
            if(mapOri[i][j]==2){
                q.push(Node(i,j));
            }
        }
    }
    vector<int> temp;
    pick(0,temp);
    
   
    int mV=0;
    for(int i=0; i<v.size();i++){
        for(int y=0; y<n;y++)
            for(int x=0;x<m;x++)
                map[y][x]= mapOri[y][x];

        
        if(map[(v[i][0]/m)][(v[i][0]%m)]!=0 || map[(v[i][1]/m)][(v[i][1]%m)]!=0 || map[(v[i][2]/m)][(v[i][2]%m)]!=0){
            continue;
        }
        map[(v[i][0]/m)][(v[i][0]%m)]=1;
        map[(v[i][1]/m)][(v[i][1]%m)]=1;
        map[(v[i][2]/m)][(v[i][2]%m)]=1;
        
        findArea(q);
        
        
        
        int cnt=0;
        for(int y=0; y<n;y++){
            for(int x=0; x<m;x++){
                if(map[y][x]==0) cnt++;
            }
        }
        if(mV<cnt){
            mV = max(mV,cnt);
        }
    }
    cout<<mV<<endl;
}
