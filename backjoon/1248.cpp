//
//  1248.cpp
//  backjoon
//
//  Created by 조연희 on 18/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
using namespace std;
int n;
char input[10][10];
int arr[10];
int idx=0;
bool check(int idx){
    for(int i=0; i<=idx;i++){
        int sum=0;
        for(int j=i;j<=idx;j++){
            sum+=arr[j];
            char test;
            if(sum>0)test='+';
            else if(sum<0)test='-';
            else test='0';
            
            if(test != input[i][j]) return false;
        }
    }
    return true;
}

void dfs(int cnt){
    if(cnt==n){
        for(int i=0; i<n;i++){
            cout<<arr[i]<<" ";
        }
        exit(0);
    }
    for(int i=-10;i<=10;i++){
        arr[cnt]=i;
        if(check(cnt)){
            dfs(cnt+1);
        }
    }
}


int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=i;j<n;j++){
            cin>>input[i][j];
        }
    }
    dfs(0);
    
}
