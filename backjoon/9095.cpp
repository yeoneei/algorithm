//
//  9095.cpp
//  backjoon
//
//  Created by 조연희 on 24/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int num[3]={1,2,3};
int n;
int countA;

void dfs(int sum){
    if(sum>n) return;
    if(n==sum){
        countA++;
    }
    for(int i=0; i<3;i++){
        sum+=num[i];
        dfs(sum);
        sum-=num[i];
    }
}

int main(){
    int T;
    cin>>T;
    for(int i=0; i<T;i++){
        countA=0;
        cin>>n;
        dfs(0);
        cout<<countA<<endl;
    }
    
}
