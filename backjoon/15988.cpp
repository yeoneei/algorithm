//
//  15988.cpp
//  backjoon
//
//  Created by 조연희 on 02/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

const long long MOD = 1000000009;
long long d[1000001];
int t,n;
long long dp(int n){
    long long &ret = d[n];
    if(ret!=0) return ret;
    ret = (dp(n-1)%MOD+dp(n-2)%MOD+dp(n-3)%MOD)%MOD;
    return ret%MOD;
}
int main(){
    cin>>t;
    d[1]=1;
    d[2]=2;
    d[3]=4;
    while(t--){
        cin>>n;
        cout<<dp(n)<<endl;
    }
}
