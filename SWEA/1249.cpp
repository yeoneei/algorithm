//
//  1249.cpp
//  backjoon
//
//  Created by 조연희 on 20/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int map[100][100];
int check[100][100];
int T,n;
char temp;
struct Node{
    int y;
    int x;
    Node(int y,int x):y(y),x(x){}
};

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void init(){
    for(int i=0; i<100;i++){
        for(int j=0; j<100;j++){
            check[i][j]=-1;
        }
    }
}

int main(){
    //ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);
    freopen("/Users/yeoni/Desktop/test/backjoon/SWEA/input.txt", "r", stdin);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        init();
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>temp;
                map[i][j]=(int)(temp-'0');
            }
        }
        
        queue<Node> qu;
        qu.push(Node(0,0));
        check[0][0]=map[0][0];
        while(!qu.empty()){
            int y = qu.front().y;
            int x = qu.front().x;
            qu.pop();
            if(y== n-1 && x==n-1){
                continue;
            }
            for(int i=0; i<4;i++){
                int ny = y +dy[i];
                int nx = x +dx[i];
                if(ny<0 || ny>=n || nx<0 || nx>=n)continue;
                if(check[ny][nx]==-1 || (check[ny][nx]!=-1 &&check[ny][nx]>check[y][x]+map[ny][nx])){
                    check[ny][nx]=check[y][x]+map[ny][nx];
                    qu.push(Node(ny,nx));
                }
            }
        }
        cout<<'#'<<tc<<" "<<check[n-1][n-1]<<'\n';
    }
}
