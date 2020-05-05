//
//  11727.cpp
//  backjoon
//
//  Created by 조연희 on 30/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
const int MOD = 10007;
int dp[1001];
int n;
int main(){
    dp[1]=1;
    dp[2]=3;
    cin>>n;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+(dp[i-2]*2)%MOD)%MOD;
    }
    cout<<dp[n]<<endl;
}
