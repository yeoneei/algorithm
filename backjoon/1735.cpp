//
//  1339.cpp
//  backjoon
//
//  Created by 조연희 on 07/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int a1, a2;
int b1, b2;
int r1, r2;
int main(){
    cin>>a1>>a2>>b1>>b2;
    r2 = a2*b2;
    r1 = a1*b2 + a2*b1;
    //유클리드 호제로 최대공약수 찾기
    int n1 = r1, n2 = r2;
    int temp;
    while(n2!=0){
        temp = n1%n2;
        n1 = n2;
        n2 = temp;
    }
    
    cout<<r1/n1<<" "<<r2/n1<<endl;
}
