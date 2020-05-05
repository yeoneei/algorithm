//
//  8993.cpp
//  backjoon
//
//  Created by 조연희 on 20/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int T;
long long n;
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        cout<<'#'<<tc<<" ";
        if(n==1 || ((n&-n)==n))cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
