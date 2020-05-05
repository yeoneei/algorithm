//
//  2156.cpp
//  backjoon
//
//  Created by 조연희 on 05/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#define MAX 10001
using namespace std;

int n;
int map[MAX];
int dp[MAX][3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>map[i];
    }
    dp[0][0]=0;
    dp[0][1]=map[0];
    dp[1][0]=map[0];
    dp[1][1]=map[1];
    dp[1][2]=map[0]+map[1];
    for(int i=2;i<n;i++){
        dp[i][2]= dp[i-1][1]+map[i];
        dp[i][1]= dp[i-1][0]+map[i];
        dp[i][0]= max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][0]);
    }
    
    int max=0;
    for(int i=0; i<3;i++){
        if(max<dp[n-1][i]){
            max = dp[n-1][i];
        }
    }
    cout<<max<<endl;
}
