//
//  1182.cpp
//  backjoon
//
//  Created by 조연희 on 16/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;


int arr[21];
int main(){
    int n,sub;
    int count=0;
    scanf("%d %d",&n,&sub);
    for(int i=0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    int size = 1<<n;
    for(int i=1;i<size;i++){
        int sum=0;
        for(int j=0; j<n;j++){
            if(i&(1<<j)){
                sum+=arr[j];
            }
        }
        if(sum==sub){
            count++;
        }
    }
    cout<<count<<endl;
}
