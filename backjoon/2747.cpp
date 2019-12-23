//
//  2747.cpp
//  backjoon
//
//  Created by 조연희 on 20/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int fibo[46];

int fiboFun(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    int &ret = fibo[n];
    if(ret!=-1) return ret;
    return ret = fiboFun(n-1)+ fiboFun(n-2);
}
int m;
int main(){
    memset(fibo, -1, sizeof(fibo));
    cin>>m;
    cout<<fiboFun(m)<<endl;
}
