//
//  4.cpp
//  backjoon
//
//  Created by 조연희 on 01/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
bool arr[20000];
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    
    int maxV =0;
    for(int i=0; i<n;i++){
        if(arr[i]) continue;
        int idx=i-1;
        while(!arr[idx-1] && idx>=0){
            idx--;
        }
        int right = i-idx;
        idx = i+1;
        while(!arr[idx+1] && idx<n){
            idx++;
        }
        int left = idx-i;
        maxV = max(maxV, min(right,left));
    }
    cout<<maxV;
}
