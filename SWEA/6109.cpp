//
//  6109.cpp
//  backjoon
//
//  Created by 조연희 on 19/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int T,n;
long long map[20][20];
long long newMap[20][20];
bool check[20][20];
string temp;

void gogo(string temp){
    if(temp=="up"){
        for(int j=0;j<n;j++)newMap[0][j]=map[0][j];
        for(int i=1; i<n;i++){
            for(int j=0; j<n;j++){
                if(map[i][j]==0) continue;
                int upIdx =i;
                while(newMap[upIdx][j]==0 && upIdx>=0){
                    upIdx--;
                }
                
                if(map[i][j]!=0 && !check[upIdx][j] && newMap[upIdx][j]==map[i][j]){
                    newMap[upIdx][j]+=map[i][j];
                    check[upIdx][j] = true;
                }else {
                    newMap[upIdx+1][j]=map[i][j];
                }
            }
            
        }
    }
    if(temp=="down"){
        for(int j=0;j<n;j++)newMap[n-1][j]=map[n-1][j];
        for(int i=n-2; i>=0;i--){
            for(int j=0; j<n;j++){
                if(map[i][j]==0) continue;
                int upIdx =i;
                while(newMap[upIdx][j]==0 && upIdx<=n-1){
                    upIdx++;
                }
                
                if(map[i][j]!=0 && !check[upIdx][j] && newMap[upIdx][j]==map[i][j]){
                    newMap[upIdx][j]+=map[i][j];
                    check[upIdx][j] = true;
                }else {
                    newMap[upIdx-1][j]=map[i][j];
                }
            }
        }
    }
    
    if(temp=="left"){
        for(int j=0;j<n;j++)newMap[j][0]=map[j][0];
        for(int i=1; i<n;i++){
            for(int j=0; j<n;j++){
                if(map[j][i]==0) continue;
                int upIdx =i;
                while(newMap[j][upIdx]==0 && upIdx>=0){
                    upIdx--;
                }
                
                if(map[j][i]!=0 && !check[j][upIdx] && newMap[j][upIdx]==map[j][i]){
                    newMap[j][upIdx]+=map[j][i];
                    check[j][upIdx] = true;
                }else {
                    newMap[j][upIdx+1]=map[j][i];
                }
            }
            
        }
    }
    
    if(temp=="right"){
        for(int j=0;j<n;j++)newMap[j][n-1]=map[j][n-1];
        for(int i=n-2; i>=0;i--){
            for(int j=0; j<n;j++){
                if(map[j][i]==0) continue;
                int upIdx =i;
                while(newMap[j][upIdx]==0 && upIdx<=n-1){
                    upIdx++;
                }
                
                if(map[j][i]!=0 && !check[j][upIdx] && newMap[j][upIdx]==map[j][i]){
                    newMap[j][upIdx]+=map[j][i];
                    check[j][upIdx] = true;
                }else {
                    newMap[j][upIdx-1]=map[j][i];
                }
            }
        }
    }
    
}

int main(){
    freopen("/Users/yeoni/Desktop/test/backjoon/SWEA/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    cin.ignore();
    for(int t=1; t<=T;t++){
        memset(newMap,0,sizeof(newMap));
        memset(map, 0,sizeof(newMap));
        memset(check,0,sizeof(check));
        cin>>n>>temp;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>map[i][j];
            }
        }
        gogo(temp);
        cout<<"#"<<t<<'\n';
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cout<<newMap[i][j]<<" ";
            }
            cout<<'\n';
        }
        
    }
}
