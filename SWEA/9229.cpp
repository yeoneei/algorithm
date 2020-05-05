//
//  9229.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int T,n,m;
int arr[1000];
int answer=-1;
int main(){
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>n>>m;
        answer=-1;
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n;i++){
                if(arr[i]+arr[j]<=m){
                    answer = max(answer,arr[i]+arr[j]);
                }
            }
        }
        cout<<"#"<<tc<<" "<<answer<<'\n';
    }
}
