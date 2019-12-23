//
//  1992.cpp
//  backjoon
//
//  Created by 조연희 on 15/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
bool map[64][64];

int allCheck(int x, int y, int size){
    bool cri = map[x][y];
    for(int i=x; i<x+size;i++){
        for(int j=y; j<y+size;j++){
            if(cri != map[i][j]) return -1;
        }
    }
    return map[x][y];
}

void compact(int x, int y , int size){
    int check = allCheck(x,y,size);
    if(check ==-1){
        cout<<"(";
        compact(x, y, size/2);
        compact(x,y+size/2,size/2);
        compact(x+size/2,y,size/2);
        compact(x+size/2,y+size/2, size/2);
        cout<<')';
    }else{
        cout<<check;
    }
    
}

int main(){
    cin>>n;
    int j=0;
    for(int i=0; i<n;){
        char temp;
        scanf("%c",&temp);
        if(temp!='\n'){
            map[i][j++] = (temp-'0');
        }
        if(j==n){
            j=0;
            i++;
        }
    }
    
    compact(0,0,n);
    
}
