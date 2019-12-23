//
//  4673.cpp
//  backjoon
//
//  Created by 조연희 on 25/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


bool num[10001]={0,};
int selfnum(int n){
    int sum=0;
    int num =n;
    while(num!=0){
        sum = sum + (num%10);
        num/=10;
    }
    return (n+sum);
}

void self(int n){
    if(n>10000) return;
    
    int a= selfnum(n);
    if(num[a]== false){
        num[a]=true;
        self(a);
    }
}

int main(){
    
    for(int i=1;i<=10000;i++){
        self(i);
    }
    
    for(int i=1;i<=10000;i++){
        if(num[i]==false){
            cout<<i<<endl;
        }
    }
    
}
