//
//  11401.cpp
//  backjoon
//
//  Created by 조연희 on 15/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int n,m;
const long long p = 1000000007;

long long power(int x, in y){
    long long ret =1;
    while(y>0){
        if(y%2){
            ret*=x;
            ret%=p;
        }
        x*=x;
        x%=p;
        y/=2;
    }
    return ret;
}

int main(){
    cin>>n>>m;
    
}
