//
//  2529.cpp
//  backjoon
//
//  Created by 조연희 on 18/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char ch[10];
int n,idx=0,arr[10];
bool check[10];
long long maxV=0;
string maxString="0";
long long minV = 9876543210;
string minString="9876543210";
void dfs(int v){
    if(n+1 == idx){
        long long r=0;
        string temp="";
        for(int i=0; i<idx;i++){
            r = r*10 + arr[i];
            temp+=(char)(arr[i]+'0');
        }
        if(maxV < r){
            maxV = r;
            maxString = temp;
        }
        if(minV > r){
            minV = r;
            minString = temp;
        }
        return ;
    }
    for(int i=0;i<=9;i++){
        if(check[i])continue;
        if(ch[idx-1]=='>'){
            if(arr[idx-1]>i){
                check[i]=1;
                arr[idx++]=i;
                dfs(i);
                idx--;
                check[i]=0;
            }else continue;
        }else{
            if(arr[idx-1]<i){
                check[i]=1;
                arr[idx++]=i;
                dfs(i);
                idx--;
                check[i]=0;
            }else continue;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>ch[i];
    }
    for(int i=0;i<=9;i++){
        memset(check,0,sizeof(check));
        idx=0;
        check[i]=1;
        arr[idx++]=i;
        dfs(i);
    }
    cout<<maxString<<endl;
    cout<<minString<<endl;
    
    
}
