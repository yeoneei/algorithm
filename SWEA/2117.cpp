//
//  2117.cpp
//  backjoon
//
//  Created by 조연희 on 11/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int T,n,m;
int map[20][20];

int getPulse(int y, int x,int k){
    int cnt=0;
    for(int i = 0; i<k;i++){
        for(int j = 0; j< 2*i+1;j++){
            if((y-k+1+i)<0 || (y-k+1+i)>=n||(x-i+j)<0 || (x-i+j)>=n) continue;
            if(map[y-k+1+i][x-i+j]==1)cnt++;
        }
    }
    for(int i=k-2;i>=0;i--){
        for(int j=0; j<i*2+1; j++){
            if(y+k-1-i<0 || y+k-1-i>=n||x-i+j<0 || x-i+j>=n) continue;
            if(map[y+k-1-i][x-i+j]==1)cnt++;
        }
    }
    return cnt;
}

int main(){
    freopen("/Users/yeoni/Desktop/test/backjoon/SWEA/input.txt", "r", stdin);
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n>>m;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>map[i][j];
            }
        }
        int maxValue =0;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                for(int k=1;k<=n+2;k++){
                    int houseNum = getPulse(i, j,k);
                    if((houseNum*m - (k*k+(k-1)*(k-1)))>=0){
                        maxValue = max(maxValue,houseNum);
                    }
                }
            }
        }
        cout<<"#"<<t<<" "<<maxValue<<endl;
    }
    
}
