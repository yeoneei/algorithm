//
//  9465.cpp
//  backjoon
//
//  Created by 조연희 on 05/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#define MAX  100002
using namespace std;
int T,n;
int map[2][MAX];
int dp[MAX][3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int t=0; t<T;t++){
        cin>>n;
        for(int i=0; i<2;i++){
            for(int j=1; j<=n;j++){
                cin>>map[i][j];
            }
        }
        dp[1][0]=0;
        dp[1][1] = map[0][1];
        dp[1][2] = map[1][1];
        for(int i=2; i<=n;i++){
            dp[i][0] = max(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = max(dp[i-1][2],dp[i-1][0])+map[0][i];
            dp[i][2] = max(dp[i-1][1],dp[i-1][0])+map[1][i];
        }
        
        int max=0;
        for(int i=0; i<3;i++){
            if(max <dp[n][i]){
                max = dp[n][i];
            }
        }
        cout<<max<<endl;
    }
}
