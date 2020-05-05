//
//  2294.cpp
//  backjoon
//
//  Created by 조연희 on 04/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<int> vc;
int cnt=0;
bool comp(int v1, int v2){
    if(v1 < v2){
        return false;
    }else{
        return true;
    }
}
int temp;
int main(){
    cin>>n>>k;
    for(int i=0; i<n;i++){
        cin>>temp;
        vc.push_back(temp);
    }
    
}
