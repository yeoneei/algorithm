//
//  1912.cpp
//  backjoon
//
//  Created by 조연희 on 01/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
long long ans[100000];

int n;
int main(){
    cin>>n;
    long long answer=0;
    for(int i=0; i<n;i++){
        cin>>arr[i];
        if(i>=1){
            ans[i]= (ans[i-1]+arr[i]>arr[i]?ans[i-1]+arr[i]:arr[i]);
            answer = max(answer,ans[i]);
        }else{
            answer = arr[i];
            ans[i]=arr[i];
        }
    }
    cout<<answer<<endl;
}
