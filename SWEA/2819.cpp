//
//  2819.cpp
//  backjoon
//
//  Created by 조연희 on 11/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

int map[4][4];
int T;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
set<string> ans;

void dfs(int y, int x, int cnt, string temp){
    if(cnt==6){
        ans.insert(temp);
        return;
    }
    
    for(int i=0; i<4;i++){
        int ny = y +dy[i];
        int nx = x +dx[i];
        if(ny<0 || ny>=4|| nx<0 || nx>=4)continue;
        dfs(ny,nx,cnt+1,temp+to_string(map[ny][nx]));
    }
}

int main(){
    cin>>T;
    for(int t=1; t<=T;t++){
        ans.clear();
        for(int i=0; i<4;i++){
            for(int j=0; j<4;j++){
                cin>>map[i][j];
            }
        }
        
        for(int i=0; i<4;i++){
            for(int j=0; j<4;j++){
                dfs(i,j,0,to_string(map[i][j]));
            }
        }
        cout<<"#"<<t<<" "<<ans.size()<<endl;
    }
    
}
