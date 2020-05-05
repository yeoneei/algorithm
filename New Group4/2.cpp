//
//  2.cpp
//  backjoon
//
//  Created by 조연희 on 05/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int ans=0;
string ans_sheet;
vector<string>sheet;
void dfs(int cnt ,int v, vector<int> list){
    if(cnt==2){
        int sum=0,start=0,end=0;
        for(int i=0; i<ans_sheet.size();i++){
            if(ans_sheet[i]!=sheet[list[0]][i] &&sheet[list[0]][i]==sheet[list[1]][i]){
                sum++;
                end++;
            }
            else{
                if(start<end) start = end;
                end=0;
            }
            
        }
        if(end>start) start=end;
        sum+=start*start;
        ans = max(ans,sum);
        return;
    }
    for(int i=v; i<sheet.size();i++){
        list.push_back(i);
        dfs(cnt+1,i+1,list);
        list.pop_back();
    }
}

int solution(string answer_sheet, vector<string> sheets){
    ans=0;
    ans_sheet = answer_sheet;
    sheet = sheets;
    vector<int> list;
    list.resize(2);
    dfs(0,0,list);
    return ans;
}   
