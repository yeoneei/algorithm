//
//  2667.cpp
//  backjoon
//
//  Created by 조연희 on 10/04/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int size;

bool map[25][25]={false};
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};

int dfs(int x, int y){
    if(map[x][y]==0) return 0;
    
    int ret=1;
    map[x][y]=0;
    for(int i=0; i<4;i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if( 0<= X && X<size && 0<=Y && Y<size && map[X][Y]==1){
            ret+= dfs(X,Y);
        }
    }
    
    return ret;
}

int main(){
    cin>>size;
    vector<int> ans;
    for(int i=0; i<size;i++){
        string a;
        cin>>a;
        for(int j=0; j<size;j++){
            map[i][j]=(a.at(j)-'0');
        }
    }
    
    for(int i=0; i<size;i++){
        for(int j=0; j<size;j++){
            int count = dfs(i,j);
            if(count!=0){
                ans.push_back(count);
            }
        }
    }
    
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}

