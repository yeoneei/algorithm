//
//  9317.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int T,n;
string t1,t2;
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        cin.ignore();
        cin>>t1>>t2;
        int cnt=0;
        for(int i=0; i<n;i++){
            if(t1[i]==t2[i]){
                cnt++;
            }
        }
        cout<<"#"<<tc<<" "<<cnt<<endl;
    }
}
