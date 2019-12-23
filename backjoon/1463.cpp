//
//  1463.cpp
//  backjoon
//
//  Created by 조연희 on 29/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
int cache[1000001];

int dp(int n){
    if(n==1) return 0;
    int &ret = cache[n];
    if(ret!=-1) return ret;
    ret = n-1;
    if(n%2 ==0){
        ret = min(ret, dp(n/2)+1);
    }
    if(n%3 ==0){
        ret = min(ret, dp(n/3)+1);
    }
    if(n-1>1){
        ret= min(ret, dp(n-1)+1);
    }
    return ret;
}
int m;
int main(){
    memset(cache, -1 , sizeof(cache));
    cin>>m;
    cout<<dp(m)<<endl;
}

