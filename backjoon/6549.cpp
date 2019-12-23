//
//  6549.cpp
//  backjoon
//
//  Created by 조연희 on 15/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;
int arr[10000];
int n;
int findMax(int left, int right){
    if(left==right) return arr[left];
    int mid = (left +right)/2;
    
    int ret = max(findMax(left,mid),findMax(mid+1,right));
    int lo =mid, hi = mid+1;
    int height = min(arr[lo],arr[hi]);
    ret = max(ret, height*2);
    while(left<lo || hi< right){
        if(hi < right && (left==lo || arr[lo-1]<arr[hi+1])){
            ++hi;
            height = min(height, arr[hi]);
        }else{
            --lo;
            height = min(height, arr[lo]);
        }
        ret = max( ret, height*(hi-lo+1));
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    cout<<findMax(0, n-1)<<endl;
}
