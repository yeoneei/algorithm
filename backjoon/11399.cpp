//
//  11399.cpp
//  backjoon
//
//  Created by 조연희 on 22/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    
    sort(v.begin(),v.end());
    
    int sum=0;
    for(int i=0; i<n;i++){
        sum+=(v.at(i)*(n-i));
    }
    
    cout<<sum<<endl;
    
}
