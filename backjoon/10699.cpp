//
//  10699.cpp
//  backjoon
//
//  Created by 조연희 on 08/04/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        string a;
        cin>>a;
        for(int i=0; i<(int)a.size();i++){
            if(a[i]=='Z'){
                a[i]='A';
            }else{
            a[i]+=1;
            }
        }
        cout<<"String #"<<i+1<<endl;
        cout<<a<<endl;
        cout<<endl;
    }
    
}

