//
//  1868.cpp
//  backjoon
//
//  Created by 조연희 on 15/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int T,n;
char map[300][300];
int cnt[300][300];
bool check[300][300];

int dx[8]={0,0,1,-1,1,-1,1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};

void dfs(int y, int x){
    for(int i=0; i<8;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=n ||nx<0 || nx>=n|| check[ny][nx])continue;
        check[ny][nx]=1;
        if(cnt[ny][nx]==0){
            dfs(ny,nx);
        }
    }
}

struct Node{
    int y;
    int x;
    Node(int y,int x):y(y),x(x){}
};

void printMap(){
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<cnt[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void printCheck(){
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<check[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

vector<Node> vc;
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        memset(check,0,sizeof(check));
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>map[i][j];
            }
        }
        
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if(map[i][j]=='*'){
                    check[i][j]=1;
                    for(int d=0; d<8;d++){
                        int ny = i+dy[d];
                        int nx = j+dx[d];
                        if(ny<0 ||ny>=n || nx<0 || nx>=n ||map[ny][nx]=='*')continue;
                        cnt[ny][nx]++;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if(map[i][j]!='*' && cnt[i][j]==0 && check[i][j]==0){
                    check[i][j]=1;
                    dfs(i,j);
                    ans++;
                }
            }
        }
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if(map[i][j]!='*' && check[i][j]==0){
                    check[i][j]=1;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
