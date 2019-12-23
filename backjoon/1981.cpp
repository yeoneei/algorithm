//
//  1981.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

int gcd(int a, int b){
    int c = a%b;
    if(c==0) return b;
    
    return gcd(b,c);
}

int main(){
    int n;
    cin>>n;
    vector<int> input;
    vector<int> diff;
    vector<int> ans;
    
    for(int i=0; i<n;i++){
        int a;
        cin>>a;
        input.push_back(a);
    }
    sort(input.begin(),input.end(),compare);
    
    if(n!=2){
        for(int i=0; i<n-1; i++){
            diff.push_back(input[i]-input[i+1]);
        }
    }else if(n==2){
        diff = input;
    }
    
    int GCD = gcd(diff[0],diff[1]);
    for(int i=2;i<diff.size();i++){
        if(GCD > diff[i]){
            GCD = gcd(GCD, diff[i]);
        }else GCD = gcd(diff[i],GCD);
    }
    for(int i=2; i<=GCD;i++){
        if(GCD%i==0){
            ans.push_back(i);
        }
    }
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}
