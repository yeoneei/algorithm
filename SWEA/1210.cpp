//
//  1210.cpp
//  backjoon
//
//  Created by 조연희 on 20/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int map[100][100];
bool check[100][100];
int y=0;
int x=0;
int T;

int dy[3]={0,0,-1};
int dx[3]={1,-1,0};
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Users/yeoni/Desktop/test/backjoon/SWEA/input.txt", "r", stdin);
    for(int tc=1; tc<=10;tc++){
        cin>>T;
        memset(check,0,sizeof(check));
        for(int i=0; i<100;i++){
            for(int j=0; j<100;j++){
                cin>>map[i][j];
                if(map[i][j]==2){
                    y=i;
                    x=j;
                }
            }
        }
        while(y!=0){
            for(int i=0; i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0 || ny>=100 || nx<0 || nx>=100 || check[ny][nx] || map[ny][nx]==0)continue;
                check[ny][nx]=1;
                y= ny;
                x = nx;
                break;
            }
        }
        cout<<"#"<<T<<" "<<x<<endl;
    }
}
