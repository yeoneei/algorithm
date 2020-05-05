//
//  1107.cpp
//  backjoon
//
//  Created by 조연희 on 29/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;


int in,n,temp;
bool check[10];
int getLen(int c){
    if(c==0){
        return !check[0];
    }
    int len=0;
    while(c>0){
        if(check[c%10]) return 0;
        len++;c/=10;
    }
    return len;
}
int main(){
    cin>>in>>n;
    for(int i=0; i<n;i++){
        cin>>temp;
        check[temp]=1;
    }
    int minV = abs(in-100);
    for(int i=0; i<=1000000;i++){
        int cnt = getLen(i);
        if(cnt>0){
            int value = abs(i-in)+cnt;
            minV = min(minV,value);
        }
    }
    cout<<minV;
    
}
