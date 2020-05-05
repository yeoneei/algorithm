//
//  13458.cpp
//  backjoon
//
//  Created by 조연희 on 26/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n,b,c;
int a[1000001];
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long cnt=0;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    cin>>b>>c;
    for(int i=0; i<n;i++){
        a[i]-=b;
        cnt++;
        if(a[i]>0){
            cnt += (a[i]/c);
            if(a[i]%c!=0)cnt++;
        }
    }
    cout<<cnt;
}
