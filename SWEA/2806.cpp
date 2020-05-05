//
//  2806.cpp
//  backjoon
//
//  Created by 조연희 on 30/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <string.h>
using namespace std;

int arr[11];
int check[11];
int T,n;
int cnt=0;

bool checkQueen(int th, int value){
    for(int i=1; i<th;i++){
        if(arr[i]==value)return false;
        if(abs(i-th)==abs(value-arr[i]))return false;
    }
    arr[th]=value;
    return true;
}


void dfs(int th){
    if(th==n+1){
        cnt++;
        return;
    }
    for(int i=1; i<=n;i++){
        if(check[i])continue;
        if(checkQueen(th, i)){
            dfs(th+1);
        }
    }
}


int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cnt=0;
        memset(check,0,sizeof(check));
        cin>>n;
        dfs(1);
        cout<<cnt<<endl;
        
    }
}
