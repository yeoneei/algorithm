//
//  11.cpp
//  backjoon
//
//  Created by 조연희 on 26/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> input;
int main(){
    cin>>n;
    input.resize(n);
    for(int i=0; i<n;i++){
        cin>>input[i];
    }
    long long zero=0;
    long long ret=0,sum=0;
    for(int i=0; i<n;i++){
        sum = max(zero,sum)+input[i];
        ret = max(sum,ret);
    }
    cout<<ret;
}
