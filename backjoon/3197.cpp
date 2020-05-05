//
//  3197.cpp
//  backjoon
//
//  Created by 조연희 on 21/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
//
//  3197.cpp
//  backjoon
//
//  Created by 조연희 on 21/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;


char map[1500][1500];
bool first[1500][1500];
int r,c;

int day[3][1500][1500];

struct Node{
    int y;
    int x;
    int num;
    Node(){}
    Node(int y, int x,int num):y(y),x(x),num(num){}
};

queue<Node> qu;

queue<Node> fQue;
queue<Node> sQue;
Node back[2];

void printMap(){
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cout<<day[0][i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cout<<day[1][i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void fistBfs(){
    qu.push(Node(back[0].y,back[0].x,0));
    qu.push(Node(back[1].y,back[1].x,1));
    first[back[0].y][back[0].x]=1;
    first[back[1].y][back[1].x]=1;
    
    while(!qu.empty()){
        int y = qu.front().y;
        int x = qu.front().x;
        int num = qu.front().num;
        qu.pop();
        int cnt=0;
        for(int i=0; i<4;i++){
            int ny= y+dy[i];
            int nx= x+dx[i];
            if(ny<0 || ny>=r || nx<0 || nx>=c ||first[ny][nx])continue;
            if(map[ny][nx]=='X')cnt++;
            if(map[ny][nx]!='.')continue;
            first[ny][nx]=1;
            qu.push(Node(ny,nx,num));
        }
        if(cnt>=1){
            if(num==0) fQue.push(Node(y,x,num));
            if(num==1) sQue.push(Node(y,x,num));
            day[num][y][x]=1;
        }
    }
}

int bacIdx=0;

void findNotwater(int y,int x,int num){
    queue<Node>temp;
    temp.push(Node(y,x,num));
    while(!temp.empty()){
        int ty = temp.front().y;
        int tx = temp.front().x;
        temp.pop();
        int cnt=0;
        for(int i=0; i<4;i++){
            int ny= ty+dy[i];
            int nx= tx+dx[i];
            if(ny<0 || ny>=r || nx<0 || nx>=c ||day[num][ny][nx])continue;
            if(map[ny][nx]!='.'){
                day[num][ny][nx]=day[num][ty][tx];
                temp.push(Node(ny,nx,num));
                cnt++;
            }
        }
        if(cnt==0){
            if(num==0)fQue.push(Node(ty,tx,0));
            if(num==1)sQue.push(Node(ty,tx,1));
        }
    }
}


int main(){
    cin>>r>>c;
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cin>>map[i][j];
            if(map[i][j]=='L'){
                back[bacIdx].y= i;
                back[bacIdx++].x=j;
            }
            
        }
    }
    fistBfs();
    bool ans=false;
    
    while(1){
        if(ans)break;
        int f = fQue.size();
        while(f--){
            int y = fQue.front().y;
            int x = fQue.front().x;
            fQue.pop();
            if(day[1][y][x]!=0){
                cout<<min(day[1][y][x],day[0][y][x])-1<<endl;
                ans=true;
                break;
            }
            for(int i=0; i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0 || ny>=r || nx<0 || nx>=c ||day[0][ny][nx]!=0)continue;
                if(map[ny][nx]=='.'){
                    day[0][ny][nx]=day[0][y][x];
                    findNotwater(ny, nx, 0);
                }
                if(map[ny][nx]=='X'){
                    day[0][ny][nx]=day[0][y][x]+1;
                    fQue.push(Node(ny,nx,0));
                    
                }
            }
        }
        if(ans)break;
        int s = sQue.size();
        while(s--){
            int y = sQue.front().y;
            int x = sQue.front().x;
            sQue.pop();
            if(day[0][y][x]!=0){
                cout<<min(day[1][y][x],day[0][y][x])-1<<endl;
                ans=true;
                break;
            }
            for(int i=0; i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0 || ny>=r || nx<0 || nx>=c ||day[1][ny][nx]!=0 ||map[ny][nx]!='X')continue;
                if(map[ny][nx]=='.'){
                    day[1][ny][nx]=day[1][y][x];
                    findNotwater(ny, nx, 1);
                }
                if(map[ny][nx]=='X'){
                    day[1][ny][nx]=day[1][y][x]+1;
                    sQue.push(Node(ny,nx,1));
                    
                }
            }
        }
    }
    
}
