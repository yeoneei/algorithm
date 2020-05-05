//
//  2019KaKao_1_2.cpp
//  backjoon
//
//  Created by 조연희 on 16/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    stringstream ss;
    string action, id, nick;
    vector <string> uid;
    map<string,string> m;
    
    for(int i=0; i<record.size();i++){
        ss.str(record[i]);
        ss>>action;
        if(action=="Enter"){
            ss>>id;
            ss>>nick;
            answer.push_back("님이 들어왔습니다.");
            uid.push_back(id);
            m[id]=nick;
        }else if(action=="Leave"){
            ss>>id;
            answer.push_back("님이 나갔습니다.");
            uid.push_back(id);
        }else{
            ss>>id;
            ss>>nick;
            m[id]=nick;
        }
        ss.clear();
        
    }
    for(int i=0; i<answer.size();i++){
        answer[i]= m[uid[i]]+answer[i];
    }
    return answer;
}
int main(){
    
}
