//
//  1309.cpp
//  backjoon
//
//  Created by 조연희 on 02/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int d[100001][3];
int n;
const int MOD =  9901;
int main(){
    cin>>n;
    d[1][0]=1;
    d[1][1]=1;
    d[1][2]=1;
    for(int i=2;i<=n;i++){
        d[i][0]=(d[i-1][0]+d[i-1][1]+d[i-1][2])%MOD;
        d[i][1]=(d[i-1][0]+d[i-1][2])%MOD;
        d[i][2]=(d[i-1][0]+d[i-1][1])%MOD;
    }
    cout<<(d[n][0]+d[n][1]+d[n][2])%MOD<<endl;
}
