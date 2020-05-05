//
//  8931.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int T,n,temp;
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        vector<int> vc;
        for(int i=0; i<n;i++){
            cin>>temp;
            if(temp==0){
                if(!vc.empty()) vc.pop_back();
            }
            if(temp!=0){
                vc.push_back(temp);
            }
        }
        int sum=0;
        for(int i=0; i<vc.size();i++){
            sum+=vc[i];
        }
        cout<<"#"<<" "<<tc<<" "<<sum<<'\n';
    }
}
