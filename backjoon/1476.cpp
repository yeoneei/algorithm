//
//  1476.cpp
//  backjoon
//
//  Created by 조연희 on 16/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int e,s,m;
    cin>>e>>s>>m;
    int count=0;
    int e1=1,s1=1,m1=1;
    while(1){
        if(e1==e && s1 ==s && m1==m){
            break;
        }
        if(e1>=15){
            e1%=15;
        }
        if(s1>=28){
            s1%=28;
        }
        if(m1 >=19){
            m1%=19;
        }
        e1++;s1++;m1++;count++;
    }
    cout<<count+1<<endl;
}
