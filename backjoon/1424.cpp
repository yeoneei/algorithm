//
//  1424.cpp
//  backjoon
//
//  Created by 조연희 on 14/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
using namespace std;

long long n,l,c;

bool checkAnswer(long long mid){
    long long len = mid*l + mid-1;
    return len<=c;
}

int main(){
    cin>>n>>l>>c;
    long long right = n;
    long long left = 1;
    
    long long len= left;
    while(left<=right){
        long long mid = (right+left)/2;
        if(checkAnswer(mid)){
            len = max(len,mid);
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    long long ans=0;
    if(len%13==0)len--;
    ans = n/len;
    if(n%len!=0){
        ans++;
        long long t = n%len;
        if(t%13==0 && (len-1)%13==0 && t+2>len)ans++;
    }
    cout<<ans;
}
