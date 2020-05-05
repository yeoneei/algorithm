//
//  9480.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T,n;
vector<string> input;
vector<bool> check;
vector<bool> ans;
int answer=0;
void dfs(int cnt, int v){
    
    if(cnt!=0){
        ans.clear();
        ans.resize(26);
        for(int i=0; i<input.size();i++){
            if(check[i]==false)continue;
            for(int j=0; j<input[i].size();j++){
                ans[(int)(input[i][j]-'a')]=true;
            }
        }
        bool ansCheck=true;
        for(int i=0; i<26;i++){
            if(ans[i]==false){
                ansCheck = false;
                break;
            }
        }
        if(ansCheck)answer++;
    }
    if(cnt==input.size())return;
    for(int i=v; i<input.size();i++){
        if(check[i])continue;
        check[i]=true;
        dfs(cnt+1,i+1);
        check[i]=false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        input.clear();
        check.clear();
        answer=0;
        cin>>n;
        cin.ignore();
        input.resize(n);
        check.resize(n);
        for(int i=0; i<n;i++){
            cin>>input[i];
        }
        dfs(0,0);
        cout<<"#"<<tc<<" "<<answer<<'\n';
    }
}
