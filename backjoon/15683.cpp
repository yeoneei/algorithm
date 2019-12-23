//
//  15683.cpp
//  backjoon
//
//  Created by 조연희 on 24/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m;
int map[8][8];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct Node{
    int x;
    int y;
    Node(int y, int x):y(y),x(x){}
};

void dfs(int y,int x, int num, vector<Node> mode){
    
}


int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
            
        }
    }
    
    
}
