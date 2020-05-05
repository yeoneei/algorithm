//
//  17837.cpp
//  backjoon
//
//  Created by 조연희 on 31/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

int map[12][12];
vector<vector<vector<int>>> ma;
struct Mar{
    int y;
    int x;
    int d;
    Mar(int y, int x, int d):y(y),x(x),d(d){}
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int changeDir(int d){
    if(d==0) return 1;
    if(d==1) return 0;
    if(d==2) return 3;
    return 2;
}
int n,k,y,x,d;
vector<Mar> mars;
int main(){
    cin>>n>>k;
    ma.resize(n);
    for(int i=0; i<n;i++){
        ma[i].resize(n);
        for(int j=0; j<n;j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<k;i++){
        cin>>y>>x>>d;
        mars.push_back(Mar(y-1,x-1,d-1));
        ma[y-1][x-1].push_back(i);
    }
    
    int t=0;
    bool answer=false;
    while(t<1000){
        if(answer){
            break;
        }
        for(int i=0; i<k;i++){
            int ny = mars[i].y+dy[mars[i].d];
            int nx = mars[i].x+dx[mars[i].d];
            bool check=false;
            int cnt=0;
            int size =(int)ma[mars[i].y][mars[i].x].size();
            if(ny<0 || ny>=n || nx<0 || nx>=n || map[ny][nx]==2){
                int dir = changeDir(mars[i].d);
                mars[i].d = dir;
                ny = mars[i].y + dy[dir];
                nx = mars[i].x + dx[dir];
                if( ny<0 || ny>=n || nx<0 || nx>=n || map[ny][nx]==2){
                    ny = mars[i].y;
                    nx = mars[i].x;
                    continue;
                }
            }
            
            if(map[ny][nx]==0){
                int beforeY = mars[i].y;
                int beforeX = mars[i].x;
                size = ma[beforeY][beforeX].size();
                for(int j=0; j<size;j++){
                    if(!check && ma[beforeY][beforeX][j]!=i){
                        continue;
                    }
                    if(!check && ma[beforeY][beforeX][j]==i){
                        cnt = size-j;
                        check=true;
                    }
                    mars[ma[beforeY][beforeX][j]].y = ny;
                    mars[ma[beforeY][beforeX][j]].x = nx;
                    ma[ny][nx].push_back(ma[beforeY][beforeX][j]);
                }
                while(cnt--){
                    ma[beforeY][beforeX].pop_back();
                }
            }
            if(map[ny][nx]==1){
                int beforeY = mars[i].y;
                int beforeX = mars[i].x;
                size = ma[beforeY][beforeX].size();
                for(int j=0; j<size;j++){
                    if(!check && ma[beforeY][beforeX][j]!=i){
                        continue;
                    }
                    if(!check && ma[beforeY][beforeX][j]==i){
                        check = true;
                        cnt = size -j;
                        break;
                    }
                }
                while(cnt--){
                    int idx = ma[beforeY][beforeX].back();
                    mars[ma[beforeY][beforeX].back()].y=ny;
                    mars[ma[beforeY][beforeX].back()].x=nx;
                    ma[ny][nx].push_back(ma[beforeY][beforeX].back());
                    ma[beforeY][beforeX].pop_back();
                }
            }
            
            if(ma[ny][nx].size()>=4){
                answer= true;
                cout<<t+1;
                break;
            }
        }
        t++;
    }
    
    if(!answer){
        cout<<-1;
        return 0;
    }
}
