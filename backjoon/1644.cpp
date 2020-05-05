//
//  1644.cpp
//  backjoon
//
//  Created by 조연희 on 09/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <math.h>
#define MAX 4000000
using namespace std;

int arr[MAX+1];
int n;
int main(){
    cin>>n;
    for(int i=2; i*i<=n;i++){
        if(arr[i]==1) continue;
        for(int j=i+i;j<=n;j+=i){
            arr[j]=1;
        }
    }
    
    int l=2;
    int r=2;
    int sum=2;
    int cnt=0;
    
    
    while(l<=r && l<=n && r<=n){
        if(sum==n){
            cnt++;
            for(int i=l+1;;i++){
                if(arr[i]==0){
                    l=i;
                    break;
                }
            }
            r=r;
            sum=0;
            for(int i=l;i<=r;i++){
                if(arr[i]==0)sum+=i;
            }
            continue;
        }else if(sum<n){
            for(int i=r+1; ;i++){
                if(arr[i]==0){
                    r=i;
                    break;
                }
            }
            sum+=r;
        }else {
            sum-=l;
            for(int i=l+1;;i++){
                if(arr[i]==0){
                    l=i;
                    break;
                }
            }
            
        }
    }
    cout<<cnt;
    
}
