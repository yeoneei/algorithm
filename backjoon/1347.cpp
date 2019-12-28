//
//  1347.cpp
//  backjoon
//
//  Created by 조연희 on 28/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#define MAX 100
using namespace std;

char map[MAX][MAX];
int y=50;
int x=50;
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int dir=0;
int sY=50;
int sX=50;
int eY=50;
int eX=50;

string temp;
int n;

int main(){
    cin>>n;
    cin.ignore();
    getline(cin,temp);
    map[y][x]='.';
    for(int i=0; i<n;i++){
        if(temp[i]=='R'){
            dir++;
            dir%=4;
        }
        if(temp[i]=='L'){
            dir--;
            dir =(dir<0?dir+4:dir);
        }
        if(temp[i]=='F'){
            x+=dx[dir];
            y+=dy[dir];
            map[y][x]='.';
            sX = (sX>x?x:sX);
            sY = (sY>y?y:sY);
            eX = (eX<x?x:eX);
            eY = (eY<y?y:eY);
        }
    }
    
    for(int i=sY; i<=eY;i++){
        for(int j=sX;j<=eX;j++){
            if(map[i][j]=='.'){
                cout<<'.';
            }else{
                cout<<'#';
            }
        }
        cout<<'\n';
    }
}

