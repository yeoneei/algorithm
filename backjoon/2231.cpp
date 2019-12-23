//
//  2231.cpp
//  backjoon
//
//  Created by 조연희 on 12/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int main(){
    cin>>n;
    
    int sum=0;
    for(int i=1;i<n;i++){
        sum=0;
        sum +=i;
        int time = i;
        while(time){
            sum+=time%10;
            time/=10;
        }
        if(sum == n){
            cout<<i<<endl;
            return 0;
        }
    }
    
    cout<<0<<endl;
    return 0;
}
