//
//  9372.cpp
//  backjoon
//
//  Created by 조연희 on 20/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int T,n,m,a,b;

int main(){
    cin>>T;
    for(int t=1; t<=T;t++){
        cin>>n>>m;
        for(int i=0; i<m;i++){
            cin>>a>>b;
        }
        cout<<n-1<<endl;
    }
}
