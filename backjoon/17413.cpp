//
//  17413.cpp
//  backjoon
//
//  Created by 조연희 on 23/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string temp;
int main(){
    getline(cin,temp);
    temp+='\n';
    stack<char> st;
    bool print = false;
    for(char ch : temp){
        
        if(print && ch!='<' && ch!='>'){
            cout<<ch;
        }
        if(!print && ch=='<'){
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            cout<<'<';
            print=true;
        }
        
        if(print && ch=='>'){
            cout<<'>';
            print=false;
        }
        if(!print && ch!='<'&& ch!='>'&& (ch==' ' || ch=='\n')){
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            cout<<' ';
        }
        if(!print && ch!='<'&& ch!='>' && ch!=' ' && ch!='\n'){
            st.push(ch);
        }
    }
}


