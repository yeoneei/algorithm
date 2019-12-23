//
//  10799.cpp
//  backjoon
//
//  Created by 조연희 on 23/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string temp;
int main(){
    getline(cin,temp);
    int len=0;
    int cnt=0;
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='('){
            cnt++;
        }
        if(temp[i]==')'){
            if(temp[i-1]=='('){
                cnt--;
                len+=cnt;
            }else{
                cnt--;
                len++;
            }
        }
    }
    cout<<len;
}

