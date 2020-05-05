//
//  3.cpp
//  backjoon
//
//  Created by 조연희 on 05/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool check[300000];

int answer=0;
void dfs(int cnt, int &n,vector<int> vc,string road){
    if(cnt<=n){
        int tempAnswer=0;
        for(int i=0; i<vc.size();i++){
            road[vc[i]]='1';
        }
        int len=0;
        for(int i=0; i<road.size();i++){
            if(road[i]=='1'){
                len++;
            }else{
                tempAnswer = max(tempAnswer,len);
                len=0;
            }
        }
        if(road[road.size()-1]=='1'){
            tempAnswer  = max(tempAnswer,len);
        }
        answer = max(answer,tempAnswer);
    }
    if(cnt==n)return;
    for(int i=0; i<road.size(); i++){
        if(check[i] || road[i]=='1')continue;
        check[i]=1;
        vc.push_back(i);
        dfs(cnt+1,n,vc,road);
        check[i]=0;
        vc.pop_back();
    }
}

int solution(string road, int n) {
    answer=0;
    vector<int>temp;
    dfs(0,n,temp,road);
    return answer;
}

int main(){
    string t = "001100";
    cout<<solution(t,5);
}
