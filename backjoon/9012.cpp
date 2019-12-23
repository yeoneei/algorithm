//
//  9012.cpp
//  backjoon
//
//  Created by 조연희 on 23/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int T;
int top=0;

string stackCheck(string str){
    int top=0;
    for(char ch : str){
        if(ch=='('){
            top++;
        }else{
            if(top<=0){
                return "NO";
            }else{
                top--;
            }
        }
    }
    if(top==0){
        return "YES";
    }else{
        return "NO";
    }
    
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>T;
    cin.ignore();
    for(int t=1;t<=T;t++){
        top=0;
        string temp;
        getline(cin,temp);
        cout<<stackCheck(temp)<<"\n";
    }
}

