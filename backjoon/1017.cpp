//
//  1017.cpp
//  backjoon
//
//  Created by 조연희 on 05/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

bool c[2001];
int n;
int f,temp;
int cnt=0;
int arr[50];
int main(){
    for (int i = 2; i<=2001; i++) {
        if (c[i]==0) {
            for (int j = i * i; j <=2001; j += i) {
                if(c[j]==false){
                    c[j]=1;
                }
            }
        }
    }
    cin>>n;
    cin>>f;
    for(int i=0; i<n-1;i++){
        cin>>temp;
        if(!c[f+temp]){
            arr[cnt++]=temp;
        }
    }
    sort(arr,arr+cnt);
    for(int i=0; i<cnt;i++){
        cout<<arr[i]<<" ";
    }
    
}
