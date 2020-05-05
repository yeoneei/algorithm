//
//  1405.cpp
//  backjoon
//
//  Created by 조연희 on 06/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
double arr[4];
bool check[30][30];
double ans;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int c;

void dfs(int y,int x,int cnt,double pro){
    if(cnt==n){
        ans+=pro;
        return;
    }
    
    for(int i=0; i<4;i++){
        int ny =y+dy[i];
        int nx =x+dx[i];
        if(check[ny][nx])continue;
        check[ny][nx]=1;
        dfs(ny,nx,cnt+1,pro*arr[i]);
        check[ny][nx]=0;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0; i<4;i++){
        cin>>arr[i];
        arr[i]*=0.01;
    }
    
    check[14][14]=1;
    dfs(14,14,0,1.0);
    cout.precision(9);
    cout<<ans<<endl;
}
