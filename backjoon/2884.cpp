//
//  2884.cpp
//  backjoon
//
//  Created by 조연희 on 01/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int h,m;
    cin>>h>>m;
    
    int newM = m-45;
    if(newM<0){
        int newH = h-1;
        if(newH>0){
            cout<<h-1<<" "<<60+newM<<endl;
        }else{
            cout<<24+newH<<" "<<60+newM<<endl;
        }
    }else{
        cout<<h<<" "<<newM;
    }
}
