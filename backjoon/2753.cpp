//
//  2753.cpp
//  backjoon
//
//  Created by 조연희 on 01/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%400==0){
        cout<<1<<endl;
    }else if((n%4)==0 && (n%100)!=0){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
}
