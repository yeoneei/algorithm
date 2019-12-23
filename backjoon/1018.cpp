//
//  1018.cpp
//  backjoon
//
//  Created by 조연희 on 14/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

char map[50][50];
int n,m;

int getBCount(int y,int x){
    int criValue = (y+x)%2;
    int cnt=0;
    int Cri = 'B';
    for(int i=y; i<y+8; i++){
        for(int j=x;j<x+8;j++){
            if((criValue == (i+j)%2) && (map[i][j]!=Cri))cnt++;
            if((criValue != (i+j)%2) && (map[i][j]==Cri))cnt++;
        }
    }
    return cnt;
}

int getWCount(int y,int x){
    int criValue = (y+x)%2;
    int cnt=0;
    int Cri = 'W';
    for(int i=y; i<y+8; i++){
        for(int j=x;j<x+8;j++){
            if((criValue == (i+j)%2) && (map[i][j]!=Cri))cnt++;
            if((criValue != (i+j)%2) && (map[i][j]==Cri))cnt++;
        }
    }
    return cnt;
}


int main(){
    cin>>n>>m;
    int j=0;
    for(int i=0; i<n;){
        char ch;
        scanf("%c",&ch);
        if(ch!='\n'){
            map[i][j]=ch;
            j++;
        }
        if(ch=='\n'){
            continue;
        }
        if(j==m){
            i++;
            j=0;
        }
    }
    
    int sum=2500;
    for(int i=0; i<n-7;i++){
        for(int j=0; j<m-7;j++){
            int getB = getBCount(i,j);
            if(sum>getB){
                sum = getB;
            }
            int getW = getWCount(i, j);
            if(sum>getW){
                sum = getW;
            }
        }
    }
    cout<<sum<<endl;
}

