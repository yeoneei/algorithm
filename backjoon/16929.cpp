//
//  16929.cpp
//  backjoon
//
//  Created by 조연희 on 24/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char map[51][51];
bool check[51][51];
int n,m;
bool getCycle=false;
void twodat(int y, int x, char ch, int dir){
    
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<n;i++){
        if(getCycle==true){
            break;
        }
        for(int j=0; j<m;j++){
            if(getCycle==true){
                break;
            }
            memset(check,0,sizeof(check));
            twodot(i,j,map[i][j]);
        }
    }
    if(getCycle){
        cout<<"YES"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
}
