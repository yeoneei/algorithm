//
//  2225.cpp
//  backjoon
//
//  Created by 조연희 on 01/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

long long d[201][201];
const long long MOD = 1000000000;
int n,k;
int main(){
    cin>>n>>k;
    d[0][0]=1;
    for(int i=1; i<=k;i++){
        for(int j=0; j<=n;j++){
            for(int l=0; l<=j;l++){
                d[i][j]+=d[i-1][j-l];
                d[i][j]%=MOD;
            }
        }
    }
    cout<<d[k][n]<<endl;
}
