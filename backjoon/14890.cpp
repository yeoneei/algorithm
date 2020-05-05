//
//  14890.cpp
//  backjoon
//
//  Created by 조연희 on 28/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int m,n;
int map[100][100];

bool colCheck(int c){
    int v = map[c][0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(v==map[c][i])cnt++;
        if(v<map[c][i]){
            if(abs(v-map[c][i])!=1) return false;
            if(cnt<m) return false;
            v = map[c][i];
            cnt=1;
        }
        if(v>map[c][i]){
            if(abs(v-map[c][i])!=1)return false;
            int idx=i;
            int len=0;
            while(map[c][i]==map[c][idx] && idx<n){
                if(len==m) break;
                idx++;len++;
            }
            if(len <m)return false;
            i = idx-1;
            cnt=0;
            v= map[c][i];
            
        }
    }
    return true;
}


bool rowCheck(int c){
    int v = map[0][c];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(v==map[i][c])cnt++;
        if(v<map[i][c]){
            if(abs(v-map[i][c])!=1) return false;
            if(cnt<m) return false;
            v = map[i][c];
            cnt=1;
        }
        if(v>map[i][c]){
            if(abs(v-map[i][c])!=1)return false;
            int idx=i;
            int len=0;
            while(map[i][c]==map[idx][c] && idx<n){
                if(len==m) break;
                idx++;len++;
            }
            if(len <m)return false;
            i = idx-1;
            cnt=0;
            v= map[i][c];
            
        }
    }
    return true;
}


int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    
    int answer=0;
    for(int i=0; i<n;i++){
        if(colCheck(i)){
            answer++;
        }
        if(rowCheck(i)){
            
            answer++;
        }
    }
    cout<<answer;
}
