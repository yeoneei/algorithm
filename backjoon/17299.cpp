//
//  17299.cpp
//  backjoon
//
//  Created by 조연희 on 24/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int cnt[1000001];
int n;
vector<int> in;
vector<int> out;
stack<int> st;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    in.resize(n);
    out.resize(n);
    for(int i=0; i<n;i++){
        cin>>in[i];
        cnt[in[i]]++;
    }
    
    for(int i=0; i<n;i++){
        while(!st.empty()){
            if(cnt[in[st.top()]]<cnt[in[i]]){
                out[st.top()]= in[i];
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
        cout<<out[i]<<" ";
    }
    
}
