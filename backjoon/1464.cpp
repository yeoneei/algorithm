//
//  1464.cpp
//  backjoon
//
//  Created by 조연희 on 30/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n[1000001];

int check(int t){
    if(t==1) return 0;
    int &ret = n[t];
    if(ret!=0) return n[t];
    ret = t-1;
    if(t%2==0){
        ret = min (ret, check(t/2)+1);
    }
    if(t%3==0){
        ret = min (ret, check(t/3)+1);
    }
    if(t-1>1){
        ret= min (ret, check(t-1)+1);
    }
    return ret;
    
}

int t;
int main(){
    n[1]=0;
    n[2]=1;
    n[3]=1;
    cin>>t;
    cout<<check(t)<<endl;
}

