
//
//  후보키.cpp
//  backjoon
//
//  Created by 조연희 on 16/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> combine;
void checkPrimary(int n,vector<vector<string>>&relation){
    vector<int> idx;
    for(int i=0; (1<<i)<(1<<relation[0].size());i++){
        if((1<<i)&n) idx.push_back(i);
    }
    set<string> set;
    for(int i=0; i< relation.size();i++){
        string temp="";
        for(int j=0; j<idx.size();j++){
            temp+=relation[i][j];
        }
        set.insert(temp);
    }
    if(set.size() == relation.size()){
        combine.push_back(n);
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    for(int i=0; i<=(1<<relation[0].size())-1;i++){
        checkPrimary(i, relation);
    }
    sort(combine.begin(),combine.end());
    for(int i=0; i<combine.size();i++){
        cout<<combine[i]<<endl;
    }
    return answer;
}
int main(){
    //[["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]
    vector<vector<string>>relation;
    vector<string> temp;
    temp.push_back("100");
    temp.push_back("ryan");
    temp.push_back("music");
    temp.push_back("2");
    relation.push_back(temp);
    temp.clear();
    temp.push_back("200");
    temp.push_back("apeach");
    temp.push_back("math");
    temp.push_back("2");
    relation.push_back(temp);
    temp.clear();
    temp.push_back("300");
    temp.push_back("tube");
    temp.push_back("computer");
    temp.push_back("3");
    relation.push_back(temp);
    temp.clear();
    temp.push_back("400");
    temp.push_back("con");
    temp.push_back("computer");
    temp.push_back("4");
    relation.push_back(temp);
    temp.clear();
    temp.push_back("500");
    temp.push_back("muzi");
    temp.push_back("music");
    temp.push_back("3");
    relation.push_back(temp);
    temp.clear();
    temp.push_back("600");
    temp.push_back("apeach");
    temp.push_back("music");
    temp.push_back("2");
    relation.push_back(temp);
    cout<<solution(relation);
}
