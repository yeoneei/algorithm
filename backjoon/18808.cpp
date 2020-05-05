//
//  18808.cpp
//  backjoon
//
//  Created by 조연희 on 25/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n,m,k;
bool map[41][41];
bool temp[10][10];
bool changeTemp[10][10];
int tempN,tempM;

bool rightMap(int y, int x, int sizeY, int sizeX, bool temp[][10]){
    if( sizeY > n || sizeX >m) return false;
    for(int i=0;i<sizeY;i++){
        for(int j=0;j <sizeX;j++){
            if(map[i+y][j+x] == 1 && temp[i][j]==1) return false;
        }
    }
    for(int i=0;i<sizeY;i++){
        for(int j=0;j <sizeX;j++){
            if(temp[i][j]==1){
                map[i+y][j+x]=1;
            }
        }
    }
    return true;
    
}

void findBlank(){
    int cntY = n - tempN+1;
    int cntX = m - tempM+1;
    //지금껄로 체크
    
    bool right = false;
    for(int i=0; i<cntY;i++){
        if(right) break;
        for(int j=0; j<cntX;j++){
            if(rightMap(i,j,tempN,tempM,temp)){
                right= true;
                break;
            }
        }
    }
    
    
    if(right) return;
    //90도 회전
    for(int i=0; i<tempN;i++){
        for(int j=0; j<tempM;j++){
            changeTemp[j][tempN-1-i]=temp[i][j];
        }
    }
    
    cntY = n- tempM+1;
    cntX = m - tempN+1;
    right = false;
    for(int i=0; i<cntY;i++){
        if(right) break;
        for(int j=0; j<cntX;j++){
            if(rightMap(i,j,tempM,tempN,changeTemp)){
                right= true;
                break;
            }
        }
    }
    if(right)return;
    
    //180도 회전
    
    for(int i= 0;i<tempM;i++){
        for(int j=0; j<tempN;j++){
            temp[j][tempM-i-1]=changeTemp[i][j];
        }
    }
    cntY = n - tempN+1;
    cntX = m - tempM+1;
    //지금껄로 체크
    
    right = false;
    for(int i=0; i<cntY;i++){
        if(right) break;
        for(int j=0; j<cntX;j++){
            if(rightMap(i,j,tempN,tempM,temp)){
                right= true;
                break;
            }
        }
    }
    if(right)return;
    
    //270도 회전
    for(int i=0; i<tempN;i++){
        for(int j=0; j<tempM;j++){
            changeTemp[j][tempN-1-i]=temp[i][j];
        }
    }
    cntY = n- tempM+1;
    cntX = m - tempN+1;
    right = false;
    for(int i=0; i<cntY;i++){
        if(right) break;
        for(int j=0; j<cntX;j++){
            if(rightMap(i,j,tempM,tempN,changeTemp)){
                right= true;
                break;
            }
        }
    }
    if(right)return;
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<k;i++){
        cin>>tempN>>tempM;
        for(int y=0; y<tempN;y++){
            for(int x=0; x<tempM;x++){
                cin>>temp[y][x];
            }
        }
        findBlank();
    }
    
    int cnt=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(map[i][j]==1)cnt++;
        }
    }
    cout<<cnt;
    
}
