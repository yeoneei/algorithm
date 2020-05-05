//
//  1918.cpp
//  backjoon
//
//  Created by 조연희 on 04/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
//
//  vector2.cpp
//  Data_sturcture
//
//  Created by 조연희 on 22/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int operatorNum(char ch){
    if(ch == '+' || ch =='-') return 1;
    else if(ch =='*' || ch =='/') return 2;
    else if(ch=='(' || ch==')')return 0;
    return -1;
}

vector<char> op;
int main(){
    string a;
    cin>>a;
    for(int i=0; i<a.size();i++){
        char ch = a[i];
        if(operatorNum(ch)==-1){
            cout<<ch;
        }else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            if(!op.empty()){
                while(!op.empty() && operatorNum(op.back())>=operatorNum(ch)){
                    cout<<op.back();
                    op.pop_back();
                }
            }
            op.push_back(ch);
        }else if(ch=='('){
            op.push_back('(');
        }else if(ch==')'){
            while(op.back()!='('){
                cout<<op.back();
                op.pop_back();
            }
            op.pop_back();
        }
    }
    while(!op.empty()){
        cout<<op.back();
        op.pop_back();
    }
    
}

