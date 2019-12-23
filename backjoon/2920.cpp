//
//  2920.cpp
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
    for(int i=0; i<8;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    
    bool das = true;
    for(int i=8;i>0;i--){
        if(i!=v.at(8-i)){
            das= false;
            break;
        }
    }
    
    if(das==true){
        cout<<"descending"<<endl;
        return 0;
    }
    
    bool ace = true;
    for(int i=1; i<=8;i++){
        if(i!=v.at(i-1)){
            ace = false;
            break;
        }
    }
    if(ace==true){
        cout<<"ascending"<<endl;
        return 0;
    }
    
    cout<<"mixed"<<endl;
}
