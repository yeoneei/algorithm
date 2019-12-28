//
//  1010.cpp
//  backjoon
//
//  Created by 조연희 on 28/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
long long c[31][31];

int a,b;
int main(){
    for(int i=0;i<31;i++){
        c[i][i] = c[i][0] = 1;
        for(int j=1;j<=i-1;j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<c[b][a]<<'\n';
    }
}
