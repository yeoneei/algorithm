//
//  1406.cpp
//  backjoon
//
//  Created by 조연희 on 23/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> lSt;
stack<char> rSt;

string temp;
int T;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin>>temp;
    cin>>T;
    for(char ch : temp){
        lSt.push(ch);
    }
    cin.ignore();
    for(int t=1; t<=T;t++){
        getline(cin,temp);
        switch (temp[0]) {
            case 'P':
                lSt.push(temp[2]);
                break;
            case'L':
                if(!lSt.empty()){
                    char ch = lSt.top();
                    lSt.pop();
                    rSt.push(ch);
                }
                break;
            case'B':
                if(!lSt.empty()){
                    lSt.pop();
                }
                break;
            case 'D':
                if(!rSt.empty()){
                    char ch = rSt.top();
                    rSt.pop();
                    lSt.push(ch);
                }
                break;
            default:
                break;
        }
    }
    while(!lSt.empty()){
        char ch = lSt.top();
        lSt.pop();
        rSt.push(ch);
    }
    while(!rSt.empty()){
        cout<<rSt.top();
        rSt.pop();
    }
}

