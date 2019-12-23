//
//  2292.cpp
//  backjoon
//
//  Created by 조연희 on 29/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int sum=1;
    int count=0;
    for(int i=1;sum<=1000000000;i++){
        if(n<=sum){
            break;
        }
        sum+=(i*6);
        count++;
    }
    
    cout<<count+1<<endl;
    
    
}
