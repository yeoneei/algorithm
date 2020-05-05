//
//  3459.cpp
//  backjoon
//
//  Created by 조연희 on 11/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;


int T;
long long n;
int main(){
    cin>>T;
    for(int t=1; t<=T;t++){
        cin>>n;
        long long x=1;
        long long i=0;
        while(x<=n){
            i++;
            if(2*x+1<=n){
                x = 2*x+1;
            }else if (2*x+1>n && 2*x<=n){
                x = 2*x;
            }else{
                break;
            }
            cout<<x<<endl;
            
        }
        cout<<"#"<<t;
        if(i%2==0){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
    }
}
