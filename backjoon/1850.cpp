//
//  1850.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    long a,b;
    cin>>a>>b;
    if(a<b){
        swap(a, b);
    }
    long diff = a-b;
    for(long i=0;i< diff;i++){
        cout<<'1';
    }
}
