//
//  1780.cpp
//  backjoon
//
//  Created by 조연희 on 15/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int pa[3];
int map[2187][2187];
int n;

int allCheck(int y, int x, int size){
    for(int i = y; i<y+size;i++){
        for(int j= x; j<x+size;j++){
            if(map[i][j]!=map[y][x]) return -100;
        }
    }
    return map[y][x];
}

void merge(int y, int x, int size){
    int t = allCheck(y, x, size);
    if(t==-100){
        int half = size/3;
        merge(y,x, half);
        merge(y,x+half,half);
        merge(y,x+half*2, half);
        merge(y+half,x, half);
        merge(y+half,x+half,half);
        merge(y+half,x+half*2, half);
        merge(y+half*2,x, half);
        merge(y+half*2,x+half,half);
        merge(y+half*2,x+half*2, half);
    }else{
        switch (t) {
            case -1:
                pa[0]++;
                break;
            case 0:
                pa[1]++;
                break;
            case 1:
                pa[2]++;
                break;
                
            default:
                break;
        }
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
    for(int i=0; i<3;i++){
        cout<<pa[i]<<endl;
    }
}
