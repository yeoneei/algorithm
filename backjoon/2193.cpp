//
//  2193.cpp
//  backjoon
//
//  Created by 조연희 on 31/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

long long dp[91][2];
int t;
int main(){
    dp[1][0]=0;
    dp[1][1]=1;
    cin>>t;
    for(int i=2; i<=t;i++){
        dp[i][0]=dp[i-1][1]+dp[i-1][0];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[t][0]+dp[t][1];
}
