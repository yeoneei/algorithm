//
//  3.cpp
//  backjoon
//
//  Created by 조연희 on 28/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

bool check[100001];
bool Cmp(string a, string b){
    if(a.size() < b.size())return true;
    else if(a.size()> b.size())return false;
    else {
        return a[0]<b[0];
    }
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<string> before;
    memset(check,0,sizeof(check));
    
    string temp="";
    for(int i=1; i<s.size()-1;i++){
        if(s[i]=='{'){
            temp="";
        }else if(s[i]=='}'){
            before.push_back(temp);
        }else{
            temp+=s[i];
        }
    }
    
    sort(before.begin(), before.end(),Cmp);
    
    for(int i=0; i<before.size();i++){
        temp="";
        for(int j=0; j<before[i].size();j++){
            if(before[i][j]==','){
                int n = stoi(temp);
                temp="";
                if(check[n]==false){
                    check[n]=1;
                    answer.push_back(n);
                }
            }else{
                temp+=before[i][j];
            }
        }
        int n = stoi(temp);
        if(check[n]==false){
            check[n]=1;
            answer.push_back(n);
        }
    }
    return answer;
}

int main(){
    vector<int>ans = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    for(int i=0; i<ans.size();i++){
        cout<<"answer  : "<<ans[i]<<endl;
    }
}
