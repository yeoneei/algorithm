//
//  3.cpp
//  backjoon
//
//  Created by 조연희 on 11/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int x;
    int y;
    Node(int y, int x):x(x),y(y){}
    Node(){}
};
int t, n,m;
Node point[2];
vector<string> map;
vector<string> ga;
vector<string> reMap;
bool check[10];
void permute(string a, int time, int idx){
    ga.push_back(a);
    if(time == n){
        return;
    }
    string temp=a;
    for(int i=idx; i<n;i++){
        if(check[i]==1) continue;
        check[i]=1;
        a+=(char)(i+'0');
        permute(a, time+1, i+1);
        check[i]=0;
        a=temp;
    }
}


int ch;
int MapCheck[10][100];
string in;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        map.clear();
        ga.clear();
        for(int i=0; i<10;i++){
            check[i]=0;
        }
        for(int i=0; i<n;i++){
            cin>>in;
            map.push_back(in);
        }
        permute("", 0, 0);
    
        int minT=100;
        for(int i=0; i<ga.size();i++){
            reMap = map;
            int newM=m;
            if(ga[i].size()>0){
                newM++;
                for(int j=0; j<ga[i].size();j++){
                    reMap[(int)(ga[i][j]-'0')] = 'X'+reMap[(int)(ga[i][j]-'0')];
                }
            }
            for(int y=0;y<n;y++){
                for(int x=0; x<m;x++){
                    MapCheck[y][x]=0;
                }
            }
            for(int j=0; j<reMap.size();j++){
                if(0<=reMap[j].find('S') && reMap[j].find('S')<=100){
                    point[0].x = (int)reMap[j].find('S');
                    point[0].y = j;
                }
                if(0<=reMap[j].find('F') && reMap[j].find('F')<=100){
                    point[1].x = (int)reMap[j].find('F');
                    point[1].y = j;
                }
            }
            queue<Node> qu;
            qu.push(Node(point[0].y, point[0].x));
            
            while(!qu.empty()){
                int x = qu.front().x;
                int y = qu.front().y;
                qu.pop();
                if(x==point[1].x && y==point[1].y){
                    minT = (minT>MapCheck[y][x]?MapCheck[y][x]:minT);
                    break;
                }
                for(int k = 0; k<4;k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(nx <0 || nx >=newM || ny<0 || ny>=n) continue;
                    if(MapCheck[ny][nx]!=0) continue;
                    if(reMap[ny][nx]=='X') continue;
                    MapCheck[ny][nx]=MapCheck[y][x]+1;
                    qu.push(Node(ny,nx));
                    
                }
            }
        }
        if(minT!=100){
            cout<<minT+1<<endl;
        }else{
            cout<<-1<<endl;
        }
    
    }
}
