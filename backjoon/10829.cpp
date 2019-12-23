//
//  10829.cpp
//  backjoon
//
//  Created by 조연희 on 19/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
long long n;
int arr[1000000];
int arrIdx=0;
int main(){
    cin>>n;
    while(n){
        int a = n%2;
        arr[arrIdx++]=a;
        n/=2;
    }
    for(int i=arrIdx-1; i>=0;i--){
        cout<<arr[i];
    }
}
