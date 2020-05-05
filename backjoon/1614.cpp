//
//  1614.cpp
//  backjoon
//
//  Created by 조연희 on 18/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int map[5][2]={
    {8,8},{6,2},{4,4},{2,6},{8,8}
};

int n,s;
int main(){
    cin>>n>>s;
    long long cnt = n;
    bool c =0;
    for(int i=0; i<s;i++){
        cnt += map[n-1][c];
        c = !c;
    }
    cout<<cnt-1;
}
