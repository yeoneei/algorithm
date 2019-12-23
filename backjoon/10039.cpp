//
//  10039.cpp
//  backjoon
//
//  Created by 조연희 on 26/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int sum=0;
    for(int i=0; i<5;i++){
        int a;
        cin>>a;
        if(a>=40){
            sum+=a;
        }else{
            sum+=40;
        }
    }
    
    int result = sum/5;
    cout<<result<<endl;
}
