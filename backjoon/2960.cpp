//
//  2960.cpp
//  backjoon
//
//  Created by 조연희 on 09/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#define MAX 1000
using namespace std;
int n,m;
bool arr[MAX+1];
int cnt=0;
int main(){
    cin>>n>>m;
    for (int i = 2; i<=n; i++) {
        if (arr[i] ==false) {
            arr[i]=1;
            cnt++;
            if(cnt==m){
                cout<<i;
                return 0;
            }
            for (int j = i * i; j <=n; j += i) {
                if(arr[j]==false){
                    arr[j]=1;
                    cnt++;
                    if(cnt==m){
                        cout<<j;
                        return 0;
                    }
                }
            }
        }
    }
    
}

