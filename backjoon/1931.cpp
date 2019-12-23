//
//  1931.cpp
//  backjoon
//
//  Created by 조연희 on 22/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main(){
    int num;
    vector<pair<int,int>> input;
    string time[100000];
    cin>>num;
    for(int i=0; i<num;i++){
        int a, b;
        cin>>a>>b;
        input.push_back(pair<int,int>(a,b));
    }
    
    sort(input.begin(),input.end(),compare);
    
    
    int now=0;
    int cnt =0;
    for(int i=0; i<num;i++){
        pair<int,int> a = input.at(i);
        if(now <= a.first){
            now = a.second;
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
    
}

