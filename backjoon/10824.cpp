//
//  10824.cpp
//  backjoon
//
//  Created by 조연희 on 25/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    a+=b;
    c+=d;
    if(a.size()<c.size()){
        b = a ;
        a = c;
        c =b;
    }
    int maxLen = a.size()>c.size()?a.size():c.size();
    int minLen = a.size()<c.size()?a.size():c.size();
    bool check = false;
    maxLen--; minLen--;
    while(minLen>=0){
        a[maxLen] = a[maxLen] +(int)(c[minLen]-'0');
        if(check){
            a[maxLen]++;
            check=false;
        }
        if(a[maxLen]>'9'){
            a[maxLen] = a[maxLen]-('9'-'0');
            a[maxLen]--;
            check =true;
        }
        maxLen--; minLen--;
    }
    
    while(maxLen>=0){
        if(check){
            a[maxLen]++;
            check=false;
        }
        if(a[maxLen]>'9'){
            a[maxLen] = a[maxLen]-('9'-'0');
            a[maxLen]--;
            check =true;
        }
        maxLen--;
    }
    if(check){
        a='1'+a;
    }
    cout<<a;
}
