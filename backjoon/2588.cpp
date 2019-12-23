//
//  2588.cpp
//  backjoon
//
//  Created by 조연희 on 30/06/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int n = a*b;
    cout<<a*(b%10)<<endl;
    b/=10;
    cout<<a*(b%10)<<endl;
    b/=10;
    cout<< a*b<<endl;
    cout<<n;
    
}
