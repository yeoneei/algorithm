//
//  1074.cpp
//  backjoon
//
//  Created by 조연희 on 19/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int r,c,cnt,n;

void dfs(int y , int x, int size){
    if(r==y && c==x){
        cout<<cnt<<endl;
        exit(0);
    }
    if(size==1){
        cnt++;
        return;
    }
    if(!(y <=r && r <y+size && x<=c && c<x+size)){
        cnt +=size*size;
        return;
    }
    int half = size/2;
    dfs(y,x,half);
    dfs(y,x+half,half);
    dfs(y+half,x, half);
    dfs(y+half,x+half, half);
}

int main(){
    cin>>n>>r>>c;
    dfs(0,0,pow(2,n));
    
}
