//
//  5.cpp
//  backjoon
//
//  Created by 조연희 on 05/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,vector<string>> m;
map<string,int> tag;

bool Cmp(pair<string,int> t1, pair<string,int> t2){
    return t1.second > t2.second;
}

vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
    for(int i=0; i<dataSource.size();i++){
        string doc = dataSource[i][0];
        for(int j=1; j<dataSource[i].size();j++){
            m[dataSource[i][j]].push_back(doc);
        }
    }
    for(int i=0; i<tags.size();i++){
        for(int j=0; j<m[tags[i]].size();j++){
            tag[m[tags[i]][j]]++;
        }
    }
    vector<pair<string,int>>temp (tag.begin(),tag.end());
    sort(temp.begin(),temp.end(),Cmp);
    vector<string> answer;
    for(int i=0; i<temp.size();i++){
        answer.push_back(temp[i].first);
    }
    return answer;
}
int main(){
    vector<vector<string>> da = {
        {"doc1", "t1", "t2", "t3"},
        {"doc2", "t0", "t2", "t3"},
        {"doc3", "t1", "t6", "t7"},
        {"doc4", "t1", "t2", "t4"},
        {"doc5", "t6", "t100", "t8"}
    };
    vector<string> tag = {"t1", "t2", "t3"};
    vector<string> answer = solution(da, tag);
    for(int i=0; i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
    
}
