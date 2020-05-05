//
//  2382.cpp
//  backjoon
//
//  Created by 조연희 on 05/05/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int T,n,m,k;
vector<int> map[100][100];
int y,x,c,d;
struct Node{
    int y;
    int x;
    long long c;
    int d;
    Node(int y, int x, int c, int d):y(y),x(x),c(c),d(d){}
};
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int chngeDir(int d){
    if(d==0)return 1;
    if(d==1)return 0;
    if(d==2)return 3;
    return 2;
}
vector<Node> input;
void mapInit(){
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(map[i][j].size()!=0)map[i][j].clear();
        }
    }
}

int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        input.clear();
        cin>>n>>m>>k;
        for(int i=0; i<k;i++){
            cin>>y>>x>>c>>d;
            input.push_back(Node(y,x,c,d-1));
        }
        while(m--){
            for(int i=0; i<input.size();i++){
                if(input[i].c==0)continue;
                int ny = input[i].y + dy[input[i].d];
                int nx = input[i].x + dx[input[i].d];
                
                if(ny<=0 || ny>=n-1 || nx<= 0 || nx>=n-1){
                    input[i].d = chngeDir(input[i].d);
                    input[i].c = input[i].c/2;
                }
                input[i].y = ny;
                input[i].x = nx;
                map[ny][nx].push_back(i);
            }
            for(int i=0; i<input.size();i++){
                if(input[i].c ==0 || map[input[i].y][input[i].x].size()<=1)continue;
                int y = input[i].y;
                int x = input[i].x;
                int idx=-1;
                long long mV=0;
                int sum=0;
                for(int j=0; j<map[y][x].size();j++){
                    sum += input[map[y][x][j]].c;
                    if(input[map[y][x][j]].c > mV){
                        mV = input[map[y][x][j]].c;
                        idx = map[y][x][j];
                    }
                    input[map[y][x][j]].c=0;
                }
                input[idx].c=sum;
            }
            mapInit();
        }
        long long sum=0;
        for(int i=0;i<input.size();i++){
            sum+=input[i].c;
        }
        cout<<"#"<<tc<<" "<<sum<<'\n';
    }
}
