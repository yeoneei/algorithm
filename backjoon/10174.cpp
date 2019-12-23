//
//  10174.cpp
//  backjoon
//
//  Created by 조연희 on 01/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

bool check(string a){
    int size = (int)a.size();
    bool ch = true;
    for(int i=0; i<size;i++){
        if(a[i]!=a[size-1-i]){

            ch = false;
            break;
        }
        if( i> size-1){
            break;
        }
    }
    return ch;
}


int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0; i<n;i++){
        string a;
        getline(cin, a);
        bool re;
        for(int j=0; j<a.size();j++){
            if(a[j]>'Z'){
                a[j]= a[j]+ 'A' - 'a';
            }
        }
        re = check(a);
        if(re){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
}
