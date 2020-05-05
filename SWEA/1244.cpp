//
//  1244.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T,t;
string input;
int answer=0;
void dfs(int v, int cnt){
    if(cnt==t){
        answer = max(stoi(input),answer);
        return;
    }
    for(int i=v; i<input.size();i++){
        for(int j=i+1; j<input.size();j++){
            if(input[i]<=input[j]){
                swap(input[i],input[j]);
                dfs(i,cnt+1);
                swap(input[i],input[j]);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>input>>t;
        answer=0;
        dfs(0,0);
        cout<<"#"<<tc<<" "<<answer<<'\n';
    }
    
}
