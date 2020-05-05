//
//  1157.cpp
//  backjoon
//
//  Created by 조연희 on 02/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

const int MOD = 10007;
int d[1001][10],n;
int main(){
    cin>>n;
    for(int i=0; i<10;i++){
        d[1][i]=1;
    }
    for(int i=2; i<=n;i++){
        for(int j=0;j<10;j++){
            for(int l=0;l<=j;l++){
                d[i][j]+=d[i-1][l];
                d[i][j]%=MOD;
            }
        }
    }
    int sum=0;
    for(int i=0; i<10;i++){
        sum+=d[n][i];
        sum%=MOD;
    }
    cout<<sum<<endl;
}
