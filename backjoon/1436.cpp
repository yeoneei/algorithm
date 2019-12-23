//
//  1436.cpp
//  backjoon
//
//  Created by 조연희 on 14/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/*
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"666"<<endl;
    }else if(n>1 &&n<=6){
        cout<<n-1<<"666"<<endl;
    }
    if(n>=7){
        cout<<"666"<<n-7<<endl;
    }
}*/

int main(){
    int n,num=0;
    cin>>n;
    for(int i=666;;i++){
        string s = to_string(i);
        if(s.find("666")!=-1) num++;
        if(n==num){
            cout<<i<<endl;
            break;
        }
    }
}
