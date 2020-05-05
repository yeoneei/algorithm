//
//  10844.cpp
//  backjoon
//
//  Created by 조연희 on 30/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#define MAX 100
using namespace std;

const int MOD = 1000000000;
long long d[MAX+1][10];
int t;
int main(){
    cin>>t;
    for(int i=1; i<10;i++){
        d[1][i]=1;
    }
    for(int i=2;i<=t;i++){
        d[i][0]= d[i-1][1]%MOD;
        d[i][1]= (d[i-1][0]%MOD+d[i-1][2]%MOD)%MOD;
        d[i][2]= (d[i-1][1]%MOD+d[i-1][3]%MOD)%MOD;
        d[i][3]= (d[i-1][2]%MOD+d[i-1][4]%MOD)%MOD;
        d[i][4]= (d[i-1][3]%MOD+d[i-1][5]%MOD)%MOD;
        d[i][5]= (d[i-1][4]%MOD+d[i-1][6]%MOD)%MOD;
        d[i][6]= (d[i-1][5]%MOD+d[i-1][7]%MOD)%MOD;
        d[i][7]= (d[i-1][6]%MOD+d[i-1][8]%MOD)%MOD;
        d[i][8]= (d[i-1][7]%MOD+d[i-1][9]%MOD)%MOD;
        d[i][9]= d[i-1][8]%MOD;
    }
    
    int sum=0;
    for(int i=0; i<10;i++){
        sum = (sum+d[t][i])%MOD;
    }
    cout<<sum;
}
