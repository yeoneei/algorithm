//
//  1562.cpp
//  backjoon
//
//  Created by 조연희 on 01/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MOD  1000000000
using namespace std;

int n;
int dp[101][10][1<<10];
int dpfunc(int k, int last, int visited){
    if(k==n){
        return visited == ((1<<10)-1);
    }
    int &ret = dp[k][last][visited];
    if(ret!= -1) return ret;
    ret =0;
    if(last>=1){
        ret +=dpfunc(k+1, last-1, visited|1<<(last-1));
    }
    if(last<=8){
        ret +=dpfunc(k+1, last+1, visited|1<<(last+1));
    }
    ret%=MOD;
    return ret;
    
}
int main(){
    cin>>n;
    int sum=0;
    memset(dp, -1,sizeof(dp));
    for(int i=1; i<10;i++){
        sum+=dpfunc(1, i, 1<<i);
        sum%=MOD;
    }
    cout<<sum;
}
