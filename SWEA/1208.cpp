//
//  1208.cpp
//  backjoon
//
//  Created by 조연희 on 28/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n,T;
int arr[100];

void dump(){
    arr[0]++;
    arr[99]--;
    sort(arr,arr+100);
}


int main(){
    for(int tc=1; tc<=1;tc++){
        cin>>n;
        for(int i=0; i<100;i++){
            cin>>arr[i];
        }
        sort(arr,arr+100);
        while(n--){
            dump();
            
        }
        cout<<arr[99]-arr[0]<<endl;
    }
}
