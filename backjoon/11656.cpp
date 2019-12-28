//
//  11656.cpp
//  backjoon
//
//  Created by 조연희 on 25/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;


bool com(string a, string b){
    if(a>b){
        return 1;
    }else {
        return -1;
    }
}
priority_queue<string,vector<string>,greater<string>> pq;
string temp;
int main(){
    getline(cin,temp);
    pq.push(temp);
    for(int i=1; i<temp.size();i++){
        pq.push(temp.substr(i,temp.size()-1));
    }
    
    while(!pq.empty()){
        cout<<pq.top()<<'\n';
        pq.pop();
    }
}
