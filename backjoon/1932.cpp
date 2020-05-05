//
//  1932.cpp
//  backjoon
//
//  Created by 조연희 on 05/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#define MAX 500
using namespace std;

int n;
int map[MAX][MAX];
int dp[MAX][MAX];
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<=i;j++){
            cin>>map[i][j];
        }
    }
    
    dp[0][0]=map[0][0];
    for(int i=1; i<n;i++){
        for(int j=0; j<=i;j++){
            if(j-1<0){
            //가장 왼쪽
                dp[i][j]=dp[i-1][j]+map[i][j];
            }else if(j>i-1 && i==j){
            //가장 오른쪽
                dp[i][j]=dp[i-1][j-1]+map[i][j];
            }else{
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+map[i][j];
            }
        }
    }
    int max=0;
    for(int i=0; i<n;i++){
        if(max< dp[n-1][i]){
            max = dp[n-1][i];
        }
    }
    cout<<max;
}
