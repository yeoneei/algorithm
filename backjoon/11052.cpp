//
//  11052.cpp
//  backjoon
//
//  Created by 조연희 on 30/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#define MAX 1000
using namespace std;

int p[MAX+1];
int d[MAX+1];
int n;
int main(){
    cin>>n;
    for(int i=1; i<=n;i++){
        cin>>p[i];
    }
    d[1]=p[1];
    for(int i=2; i<=n;i++){
        d[i]=p[i];
        for(int j=i-1; j>0;j--){
            d[i] = min(d[i-j]+p[j],d[i]);
        }
    }
    cout<<d[n]<<endl;
}
