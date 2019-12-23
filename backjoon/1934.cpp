//
//  1934.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b){
    long long int n = a% b;
    if(n==0){
        return b;
    }
    return gcd(b, n);
}


int main(){
    long long int a, b;
    cin>>a>>b;
    if(a<b){
        swap(a,b);
    }
    long long int G = gcd(a,b);
    while(G--){
        cout<<1;
    }

}
