//
//  7344.cpp
//  backjoon
//
//  Created by 조연희 on 02/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T,n,fi,se;
int main(){
    cin>>T;
    for(int t=0; t<T;t++){
        vector<pair<int,int>> vc;
        vector<bool>  check;
        cin>>n;
        for(int i=0; i<n;i++){
            cin>>fi>>se;
            vc.push_back(make_pair(fi, se));
        }
        sort(vc.begin(),vc.end());
        int cnt=0;
        check.resize(n);
        for(int i=0; i<n;i++){
            if(check[i])continue;
            check[i]=1;
            cnt++;
            int value = vc[i].second;
            for(int j=i+1; j<n;j++){
                if(!check[j] &&value <= vc[j].second){
                    value = vc[j].second;
                    check[j]=1;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
