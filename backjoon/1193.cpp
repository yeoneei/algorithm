//
//  1193.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;


long long oper(int t){
    return t*(t+1)/2;
}
int n;
int main(){
    cin>>n;
    if(n==1){
        cout<<"1/1";
        return 0;
    }
    //구간 알아내기
    int idx=1;
    int value=1;
    while(value<n){
        idx++;
        value = oper(idx);
        
    }
    int num = oper(idx-1);
    num++;
    int dif = n-num;
    if(idx%2==1){
        cout<<idx-dif<<"/"<<dif+1;
    }else{
        cout<<dif+1<<"/"<<idx-dif;
    }
    
}
