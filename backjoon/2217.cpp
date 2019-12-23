//
//  2217.cpp
//  backjoon
//
//  Created by 조연희 on 22/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

int main(){
    int n;
    cin>>n;
    vector<int> m;
    vector<int> output;
    
    for(int i=0; i<n;i++){
        int a;
        cin>>a;
        m.push_back(a);
    }
    
    sort(m.begin(),m.end());
    for(int i=0; i<n;i++){
        int kg = m.at(i)*(n-i);
        output.push_back(kg);
    }
    
    sort(output.begin(),output.end(),compare);
    
    cout<<output.at(0)<<endl;
    
    
    
    
}
