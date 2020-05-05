//
//  33.cpp
//  backjoon
//
//  Created by 조연희 on 25/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;



vector<string> sepoerat(string t){
    string after="";
    string before="";
    for(int i=0; i<t.size();i++){
        if(!(t[i]>='0' && t[i]<='9')){
            before+=t[i];
        }else after+=t[i];
    }
    
    vector<string>ans;
    ans.push_back(before);
    ans.push_back(after);
    return ans;
}

map<string,map<string,int>> m;
map<string,int> m2;

string solution(vector<string> registered_list, string new_id) {
    m.clear();
    m2.clear();
    for(int i=0; i<registered_list.size();i++){
        vector<string> temp = sepoerat(registered_list[i]);
        if(temp[1]!=""){
             m[temp[0]][temp[1]]++;
        }else{
            m2[temp[0]]++;
        }
       
    }
    string answer="";
    vector<string> temp = sepoerat(new_id);
    bool empty = false;
    if(temp[1]=="" && m2[temp[0]]==0){
        empty=true;
    }
    if(temp[1]!=""  && m[temp[0]][temp[1]]==0){
        empty=true;
    }
    
    if(empty){
        answer=new_id;
        return answer;
    }
    int idx=0;
    if(temp[1]!=""){
        idx =stoi(temp[1].c_str());
    }
    while(1){
        idx++;
        string ss = to_string(idx);
        if(m[temp[0]][ss]==0){
            break;
        }
    }
    answer = temp[0]+to_string(idx);
    
    return answer;
}



int main(){
    vector<string> list = {"bird99", "bird98", "bird101", "gotoxy"};
    cout<<solution(list, "bird98");
}

