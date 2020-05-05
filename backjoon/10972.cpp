//
//  10972.cpp
//  backjoon
//
//  Created by 조연희 on 28/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n,a;
int arr[10010];
bool comp(int a, int b){
    return  a >b;
}
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    
    int idx=-1;
    for(int i=n-1;i>0;i--){
        if(arr[i-1]>arr[i]){
            idx =i;
            break;
        }
    }
    
    if(idx!=-1){
        for(int j=n-1;j>=idx;j--){
            if(arr[idx-1] > arr[j]){
                swap(arr[idx-1], arr[j]);
                break;
            }
        }
        sort(arr+idx,arr+n,comp);
        for(int i=0; i<n;i++){
            cout<<arr[i]<<" ";
        }
    }else{
        cout<<"-1";
    }
    
}
