//
//  2702.cpp
//  backjoon
//
//  Created by 조연희 on 13/05/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b ==0) return a;
    return  gcd(b, a%b);
}


int main(){
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        int a, b;
        cin>>a>>b;
        int m = (a>b? gcd(a,b): gcd(b,a));
        int n = a*b/m;
        cout<<n<<" "<<m<<endl;
    }
}

