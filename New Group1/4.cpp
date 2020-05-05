//
//  4.cpp
//  backjoon
//
//  Created by 조연희 on 14/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int main(){
    cin>>n;
    while(n%2!=0){
        cout<<'7';
        n-=3;
    }
    while(n){
        n-=2;
        cout<<'1';
    }
    
}
