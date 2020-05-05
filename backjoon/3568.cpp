//
//  3568.cpp
//  backjoon
//
//  Created by 조연희 on 11/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string input;
vector<string> tokenizer(string temp){
    vector<string> result;
    stringstream ss;
    ss.str(temp);
    string k;
    while(getline(ss,k,',')){
        result.push_back(k);
    }
    return result;
}
int main(){
    
    getline(cin,input);
    vector<string> ans = tokenizer(input);
    string common="";
    for(int i=0; i<ans[0].size();i++){
        if(ans[0][i]==' '){
            ans[0] = ans[0].substr(i);
            break;
        }
        common +=ans[0][i];
    }
    for(int i=0; i<ans.size();i++){
        string name="";
        int idx=1;
        while(idx<ans[i].size()){
            if(ans[i][idx]=='*'|| ans[i][idx]=='&' ||ans[i][idx]=='[' || ans[i][idx]==';'){
                break;
            }
            name+=ans[i][idx];
            idx++;
        }
        string oper="";
        for(int j= (int)ans[i].size()-1; j>=idx;j--){
            if(ans[i][j]==';')continue;
            if(ans[i][j]==']'){
                oper+="[]";
                j--;
                continue;
            }
            oper+=ans[i][j];
        }
        
        cout<<common<<oper<<" "<<name<<";"<<endl;
        
    }
    
}
