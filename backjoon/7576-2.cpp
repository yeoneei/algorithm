//
//  7576-2.cpp
//  backjoon
//
//  Created by 조연희 on 07/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int n,m;
int map[1000][1000];

struct Node{
    int x;
    int y;
    Node(int y, int x):x(x),y(y){}
};
queue<Node> qu;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


int main(){
    cin>>m>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                qu.push(Node(i,j));
            }
        }
    }
    
    bool check = false;
    for(int i=0; i<n;i++){
        if(check==true){
            break;
        }
        for(int j=0; j<m;j++){
            if(map[i][j]==0){
                check=true;
                break;
            }
        }
    }
    if(check== false){
        cout<<0<<endl;
        return 0;
    }
    
    int day=0;
    while(!qu.empty()){
        day++;
        check = false;
        int size  = (int)qu.size();
        for(int i=0; i<size;i++){
            int x = qu.front().x;
            int y = qu.front().y;
            qu.pop();
            for(int j=0; j<4;j++){
                int nx = x+dx[j];
                int ny = y+dy[j];
                if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
                if(map[ny][nx]==0){
                    map[ny][nx]=1;
                    qu.push(Node(ny,nx));
                }
                
            }

        }
        for(int i=0; i<n;i++){
            if(check==true){
                break;
            }
            for(int j=0; j<m;j++){
                if(map[i][j]==0){
                    check=true;
                    break;
                }
            }
        }
        if(check==false){
            break;
        }
    }
    
   
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(map[i][j]==0){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<day<<endl;
    
}
