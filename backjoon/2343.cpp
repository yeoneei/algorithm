//
//  2343.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> input;

bool checkSum(int mid){
    int sum=0;
    int cnt=1;
    for(int i=0; i<input.size();i++){
        if(sum+input[i]>mid){
            cnt++;
            sum=input[i];
        }else{
            sum+=input[i];
        }
    }
    return cnt>m;
}
int main(){
    cin>>n>>m;
    input.resize(n);
    int l =0;
    int r =0;
    for(int i=0; i<n;i++){
        cin>>input[i];
        r+=input[i];
        l = max(l,input[i]);
    }
    int answer=r;
    while(l<=r){
        int mid = (l+r)/2;
        if(checkSum(mid)){
            l = mid+1;
        }else{
            answer = min(mid,answer);
            r = mid-1;
        }
    }
    cout<<answer;
}
