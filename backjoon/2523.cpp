//
//  2523.cpp
//  backjoon
//
//  Created by 조연희 on 12/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int main(){
    cin>>n;
    if(n==1){
        cout<<'*';
        return 0;
    }
    int t=n;
    while(t--){
        for(int i=0; i<(n/2+n%2);i++){
            cout<<"* ";
        }
        cout<<endl;
        for(int i=0; i<(n/2);i++){
            cout<<" *";
        }
        cout<<endl;
    }
}
