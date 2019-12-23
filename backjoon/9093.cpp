//
//  9093.cpp
//  backjoon
//
//  Created by 조연희 on 27/11/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void reverseStr(string str){
    stack<char> st;
    for(char ch : str){
        if(ch==' ' || ch=='\n'){
            while(!st.empty()){
                char temp = st.top();
                st.pop();
                cout<<temp;
            }
            cout<<" ";
        }else{
            st.push(ch);
        }
    }
}
int T;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>T;
    cin.ignore();
    for(int t = 1; t<=T;t++){
        string temp;
        getline(cin, temp);
        temp+='\n';
        reverseStr(temp);
        cout<<'\n';
    }
}

