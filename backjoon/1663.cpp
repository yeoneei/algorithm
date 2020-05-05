//
//  1663.cpp
//  backjoon
//
//  Created by 조연희 on 14/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

long long tt[101];
string dp[3]={"X","YZ","ZX"};

long long num[3];
long long temp[3];

char t;
int n,m;
long long k;
void getChar(long long s, long long e, long long idx, long long now){
    if(now==0 || now==1 || now==2){
        cout<<dp[now][idx-s];
        return;
    }else{
        long long mid = s+tt[now-3];
        if(idx<mid){
            getChar(s, mid-1, idx, now-3);
        }else{
            getChar(mid, e, idx, now-2);
        }
    }
    
}

int main(){
    num[0]=1;
    tt[0]=1;
    cin>>n;
    cin>>m;
    for(int i=1; i<m;i++){
        temp[1]+=num[0];
        temp[2]+=num[0];
        temp[0]+=num[2];
        temp[2]+=num[1];
        for(int j=0; j<3;j++){
            num[j]=temp[j];
            tt[i]+=temp[j];
            temp[j]=0;
        }
    }
    
    if(n==1) cout<<tt[m-1];
    if(n==2){
        cin>>k;
        getChar(0, tt[m-1]-1, k-1, m-1);
        
    }
    if(n==3){
        cin>>t;
        if(t=='X')cout<<num[0];
        if(t=='Y')cout<<num[1];
        if(t=='Z')cout<<num[2];
    }
}
