//
//  6236.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> in;

bool checkMid(int mid){
    int cnt=1;
    int sum=0;
    for(int i=0; i< in.size();i++){
        if(sum+in[i]>mid){
            cnt++;
            sum=in[i];
        }else{
            sum+=in[i];
        }
    }
    return cnt>m;
}

int main(){
    cin>>n>>m;
    in.resize(n);
    int l=0,r=0;
    for(int i=0; i<n;i++){
        cin>>in[i];
        l = min(l,in[i]);
        r = max(r,in[i]);
    }
    int ans=r;
    while(l<=r){
        int mid = (l+r)/2;
        if(checkMid(mid)){
            l = mid+1;
        }else{
            ans = min(ans,mid);
            r = mid-1;
            
        }
    }
    cout<<ans;
}
