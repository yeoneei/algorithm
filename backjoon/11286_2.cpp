//
//  11286_2.cpp
//  backjoon
//
//  Created by 조연희 on 05/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int n,temp;
priority_queue<pair<int,int>> qu;
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>temp;
        if(temp==0){
            if(qu.empty()){
                cout<<0<<'\n';
            }else{
                cout<<-qu.top().second<<'\n';
                qu.pop();
            }
        }else{
            
            qu.push(make_pair(-abs(temp), -temp));
        }
    }
}

