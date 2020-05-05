//
//  1654.cpp
//  backjoon
//
//  Created by 조연희 on 14/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int k,n;
vector<long long> in;

bool checkLAN(long long mid){
    long long cnt=0;
    for(int i=0; i<in.size();i++){
        cnt = cnt + in[i]/mid;
    }
    
    return cnt>=n;
}


int main(){
    cin>>k>>n;
    in.resize(k);
    long long l=1,r=0;
    for(int i=0; i<k;i++){
        cin>>in[i];
        r = max(in[i],r);
    }
    long long ans=l;
    while(l<=r){
        long long mid = (l+r)/2;
        
        if(checkLAN(mid)){
            ans = max(ans,mid);
            //n개보다 많이 만들어 질때
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<ans;
    
}
