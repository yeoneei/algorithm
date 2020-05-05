//
//  2220.cpp
//  backjoon
//
//  Created by 조연희 on 09/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int n;
int arr[100001];
int main(){
    cin>>n;
    arr[1]=1;
    for(int i=2; i<=n;i++){
        arr[i]=1;
        arr[i-1]=i;
        int here = i-1;
        while(here>1 && arr[here] >arr[here/2]){
            swap(arr[here],arr[here/2]);
            here/=2;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}
