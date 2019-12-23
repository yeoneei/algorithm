//
//  1110.cpp
//  backjoon
//
//  Created by 조연희 on 25/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    
    int n= num;
    int count=0;
    while(1){
        int second = n%10;
        int sum = ((n/10) + (n%10))%10;
        n = second*10+sum;
        if(n == num){
            count++;
            break;
        }else count++;
    }
    
    cout<<count<<endl;
    
}
