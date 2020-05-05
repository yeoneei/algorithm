//
//  18290.cpp
//  backjoon
//
//  Created by 조연희 on 01/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n,m,k;
int map[11][11];
int endM;
int check[11][11];
int answer = -1000000;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int cnt, int sum){
    if(cnt==k){
        answer=max(answer,sum);
        return;
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(check[i][j]!=0) continue;
            check[i][j]++;
            sum+=map[i][j];
            for(int k=0; k<4;k++){
                int ny= i+dy[k];
                int nx = j+dx[k];
                if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
                check[ny][nx]++;
            }
            dfs(cnt+1,sum);
            sum-=map[i][j];
            check[i][j]--;
            for(int k=0; k<4;k++){
                int ny= i+dy[k];
                int nx = j+dx[k];
                if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
                check[ny][nx]--;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>k;
    endM = n*m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
        }
    }
    dfs(0,0);
    cout<<answer;
}
