//
//  1206.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[1000],n;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    for(int tc=1;tc<=10;tc++){
        cin>>n;
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        long long sum=0;
        for(int i=0; i<n;i++){
            int maxV =0;
            for(int j=i-2;j<=i+2;j++){
                if(j<0 || j>=n)continue;
                maxV = max(maxV,arr[j]);
            }
        }
        cout<<'#'<<tc<<" "<<sum<<'\n';
        
    }
    
}
