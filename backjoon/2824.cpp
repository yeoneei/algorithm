//
//  2824.cpp
//  backjoon
//
//  Created by 조연희 on 09/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;


bool check[MAX+2];
int sub[MAX+2][2];
long long maxV=0;

void subT(long long v,int t){
    while(v>1){
        for(int i=2; i<=v;i++){
            if(check[i])continue;
            if(v%i==0){
                sub[i][t]++;
                maxV = maxV<i?i:maxV;
                v/=i;
                break;
            }
        }
    }
}

int n,m;
long long temp;
int main(){
    for(int i=2; i*i<=MAX;i++){
        if(check[i]==1) continue;
        for(int j=i+i;j<=MAX;j+=i){
            check[j]=1;
        }
    }
    
    cin>>n;
    while(n--){
        cin>>temp;
        subT(temp,0);
    }
    
    cin>>m;
    while(m--){
        cin>>temp;
        subT(temp,1);
    }
    
    
    long long ans=1;
    for(int i=2; i<=maxV;i++){
        if(check[i]==1 || sub[i][0]==0 || sub[i][1]==0)continue;
        int m = min(sub[i][0],sub[i][1]);
        while(m--){
            ans*=(i%MAX);
            ans%=MAX;
        }
    }
    
    cout<<ans;
    
}
