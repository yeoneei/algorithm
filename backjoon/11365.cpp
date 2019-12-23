//
//  11365.cpp
//  backjoon
//
//  Created by 조연희 on 01/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    while(1){
        string a;
        getline(cin,a);
        if(a=="END"){
            break;
        }
        for(int i=(int)a.size()-1; i>=0;i--){
            cout<<a[i];
        }
        cout<<endl;
    }
}
