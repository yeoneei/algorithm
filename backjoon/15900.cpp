//
//  15900.cpp
//  backjoon
//
//  Created by 조연희 on 30/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
const int MOD = 1000000009;
long long d[100001][4];

int t,a;
int main(){
    cin>>t;
    d[1][1]=1;
    d[2][2]=1;
    d[3][1]=1;
    d[3][2]=1;
    d[3][3]=1;
    while(t--){
        cin>>a;
        for(int i=4;i<=a;i++){
            d[i][1]=(d[i-1][2]+d[i-1][3])%MOD;
            d[i][2]=(d[i-2][1]+d[i-2][3])%MOD;
            d[i][3]=(d[i-3][1]+d[i-3][2])%MOD;
        }
        cout<<(d[a][1]%MOD+d[a][2]%MOD+d[a][3]%MOD)%MOD<<endl;
    }
}
