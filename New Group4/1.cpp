//
//  1.cpp
//  backjoon
//
//  Created by 조연희 on 05/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solution(string inputString) {
    int answer = -1;
    
    int cnt=0;
    stack<char> st;
    bool check = true;
    for(int i=0; i<inputString.size();i++){
        char ch = inputString[i];
        if(ch =='(' || ch=='{' || ch=='<' || ch=='['){
            st.push(ch);
        }else if(ch ==')' || ch=='}' || ch=='>' || ch==']'){
            if(st.empty()){
                check = false;
                break;
            }
            char temp = st.top();
            st.pop();
            if((ch== ')' && temp!='(') ||(ch== '}' && temp!='{')  ||(ch== '>' && temp!='<')||(ch== ']' && temp!='[')){
                check = false;
                break;
            }
            cnt++;
        }
    }
    if(!st.empty()) return -1;
    
    if(!check) return -1;
    return cnt;
}

int main(){
    string t = "line [plus]";
    cout<<solution(t);
}
