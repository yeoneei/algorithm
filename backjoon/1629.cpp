//
//  1629.cpp
//  backjoon
//
//  Created by 조연희 on 15/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
long long n;
int m,k;
long long pow2(long long b, int idx, int mod){
    if(idx==1) return b;
    if(idx%2 ==0){
        long long r = pow2(b,idx/2,mod);
        return (r%mod*r%mod)%mod;
    }else{
        return (b*pow2(b,idx-1,mod))%mod;
    }
}
int main(){
    cin>>n>>m>>k;
    cout<<pow2(n,m,k)%k<<endl;
}
