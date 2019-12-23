//
//  vector.cpp
//  Data_sturcture
//
//  Created by 조연희 on 22/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> input,stack;
    vector<char> output;
    
    for(int i=0; i<n;i++){
        int a;
        cin>>a;
        input.push_back(a);
    }
    int orderIndex=1;
    int pre  = -100;
    bool st = true;
    for(int i=0; i<n;i++){
        int now = input.at(i);
        if(pre < now){
            for(; orderIndex<=now;orderIndex++){
                stack.push_back(orderIndex);
                output.push_back('+');
            }
            stack.pop_back();
            output.push_back('-');
        }else{
            if(pre >now){
                int a= stack.back();
                if(now != a){
                    st = false;
                    break;
                }
                else {
                    output.push_back('-');
                    stack.pop_back();
                }
            }
        }
        pre = now;
    }
    
    if(!st) cout<<"NO";
    else {
        for(int i=0; i<output.size();i++){
            cout<<output.at(i)<<"\n";
        }
    }
    
    
}

