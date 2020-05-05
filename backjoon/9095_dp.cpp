//
//  9095_dp.cpp
//  backjoon
//
//  Created by 조연희 on 30/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n[12];
int t,a;
int main(){
    cin>>t;
    n[1]=1;
    n[2]=2;
    n[3]=4;
    while(t--){
        cin>>a;
        for(int i=4;i<=a;i++){
            if(n[i]!=0) continue;
            n[i]= n[i-1]+n[i-2]+n[i-3];
        }
        cout<<n[a]<<endl;
    }
}
