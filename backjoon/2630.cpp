//
//  2630.cpp
//  backjoon
//
//  Created by 조연희 on 15/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int pa[2];
bool map[128][128];

int allCheck(int y, int x, int size){
    int cri = map[y][x];
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(map[i][j]!=cri){
                return -1;
            }
        }
    }
    return cri;
}

void merge(int y,int x, int size){
    int p = allCheck(y,x,size);
    if(p == -1){
        merge(y,x,size/2);
        merge(y,x+size/2,size/2);
        merge(y+size/2,x,size/2);
        merge(y+size/2,x+size/2,size/2);
    }else{
        pa[p]++;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
        }
    }
    
    merge(0,0,n);
    cout<<pa[0]<<endl;
    cout<<pa[1]<<endl;
}
