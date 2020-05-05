//
//  2.cpp
//  backjoon
//
//  Created by 조연희 on 01/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string temp;
int n;
vector<int> input;
vector<bool> check;

int cnt=0;
int allCnt=0;

void dfs(int c,vector<int> list){
    if(c==cnt){
        if(++allCnt==n){
            for(int i=0; i<list.size();i++){
                cout<<list[i];
            }
        }
        return;
    }
    for(int i=0; i<input.size();i++){
        if(check[i])continue;
        check[i]=1;
        list.push_back(input[i]);
        dfs(c+1,list);
        check[i]=0;
        list.pop_back();
    }
}

int main(){
    string in;
    getline(cin, in);
    stringstream ss(in);
    string tmp;
    while (getline(ss, tmp, ' ')) {
        cnt++;
        input.push_back(atoi(tmp.c_str()));
        check.push_back(0);
    }
    cin>>n;
    sort(input.begin(),input.end());
    vector<int> vc;
    dfs(0,vc);
    
}
