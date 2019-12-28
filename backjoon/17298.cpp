//
//  17298.cpp
//  backjoon
//
//  Created by 조연희 on 23/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int n;
int in[1000000];
int out[1000000];
stack<int> st;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>in[i];
        while(!st.empty()){
            int temp = st.top();
            if(in[temp]<in[i]){
                out[temp]=in[i];
                st.pop();
            }else{
                break;
            }
        }
        st.push(i);
    }
    while(!st.empty()){
        out[st.top()]=-1;
        st.pop();
    }
    for(int i=0; i<n;i++){
        cout<<out[i]<<' ';
    }
}

