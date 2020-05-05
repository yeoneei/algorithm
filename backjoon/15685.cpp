//
//  15685.cpp
//  backjoon
//
//  Created by 조연희 on 03/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int n,x,y,d,g;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
bool map[101][101];

vector<int> dragonCurb(int n){
    vector<int> v1;
    v1.push_back(0);
    while(n--){
        int size = (int)v1.size();
        for(int i=size-1; i>=0;i--){
            int temp = v1[i];
            temp = ((temp+1)%4);
            v1.push_back(temp);
        }
    }
    return v1;
}
vector<int> temp;
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>x>>y>>d>>g;
        temp = dragonCurb(g);
        map[y][x]=1;
        for(int j=0; j<temp.size();j++){
            y = y+dy[((temp[j]+d)%4)];
            x = x+dx[((temp[j]+d)%4)];
            map[y][x]=1;
        }
    }
    int cnt=0;
    for(int i=0; i<100;i++){
        for(int j=0; j<100;j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
                cnt++;
            }
        }
    }
    cout<<cnt;
}

