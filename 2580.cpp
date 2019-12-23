//
//  2580.cpp
//  backjoon
//
//  Created by 조연희 on 31/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int map[9][9];
int check[81];
int num;
int dx[81];
int dy[81];

bool checkRowCol(int y, int x,int num){
    for(int i=0; i<9;i++)
    {
        if(map[i][x]==num) return false;
        if(map[y][i]==num) return false;
    }
    int nx = x/3;
    int ny = y/3;
    for(int i=ny*3; i<ny*3+3;i++){
        for(int j=nx*3 ; j<nx*3+3;j++){
            if(map[i][j]==num) return false;
            
        }
    }
    return true;
}


void sudo(int n){
    
    if(n== num){
        for(int i=0; i<9;i++){
            for(int j=0; j<9;j++){
                cout<<map[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    for(int i=1; i<=9;i++){
        if(!checkRowCol(dy[n], dx[n], i)) continue;
        map[dy[n]][dx[n]]=i;
        sudo(n+1);
        map[dy[n]][dx[n]]=0;
    }
    
}

int main(){
    for(int i=0; i<9;i++){
        for(int j=0; j<9;j++){
            cin>>map[i][j];
            if(map[i][j]==0){
                dx[num]=j;
                dy[num]=i;
                num++;
                
            }
        }
    }
    sudo(0);
    
}
