//
//  1974.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int map[9][9];
int T;

bool check[10];

bool checkRow(int r){
    memset(check,0,sizeof(check));
    for(int i=0; i<9;i++){
        if(check[map[r][i]]==1)return false;
        check[map[r][i]]=1;
    }
    return true;
}

bool checkCol(int c){
    memset(check,0,sizeof(check));
    for(int i=0; i<9;i++){
        if(check[map[i][c]]==1)return false;
        check[map[i][c]]=1;
    }
    return true;
}


bool checkBx(int r, int c){
    memset(check,0,sizeof(check));
    for(int i=r; i<r+3;i++){
        for(int j=c; j<c+3;j++){
            if(check[map[i][j]]==1)return false;
            check[map[i][j]]=1;
        }
    }
    return true;
}
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        for(int i=0; i<9;i++){
            for(int j=0; j<9;j++){
                cin>>map[i][j];
            }
        }
        bool ans=true;
        for(int i=0; i<9;i++){
            if(!checkCol(i)){
                ans= false;
                break;
            }
            if(!checkRow(i)){
                ans = false;
                break;
            }
        }
        for(int i=0; i<9;i+=3){
            for(int j=0; j<9;j+=3){
                if(!checkBx(i, j)){
                    ans=false;
                    break;
                }
            }
        }
        cout<<"#"<<tc<<' '<<ans<<'\n';
    }
}
