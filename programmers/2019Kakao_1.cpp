//
//  2019Kakao_1.cpp
//  backjoon
//
//  Created by 조연희 on 06/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Node{
    bool in=false;
    string name;
    vector<int> list;
};
unordered_map<string, Node>map;

vector<string> findUser(string temp){
    vector<string> answer;
    int idx=0;
    string uid = "";
    while(idx < temp.size()){
        if(temp[idx]==' '){
            break;
        }
        uid+=temp[idx++];
    }
    answer.push_back(uid);
    idx++;
    if(idx < (int)temp.size()){
        answer.push_back(temp.substr(idx));
    }
    return answer;
}

vector<string> solution(vector<string> record) {
    map.clear();
    vector<string> answer;
    vector<bool> inout;
    vector<string> info;
    for(int i=0; i<record.size();i++){
        if(record[i][0]=='E'){
            info = findUser(record[i].substr(6));
            map[info[0]].in =true;
            if(map[info[0]].name != info[1]){
                for(int i=0; i<map[info[0]].list.size();i++){
                    int idx = map[info[0]].list[i];
                    if(inout[idx]==1){
                        answer[idx]= info[1]+"님이 들어왔습니다.";
                    }else{
                        answer[idx]= info[1]+"님이 나갔습니다.";
                    }
                }
            }
            map[info[0]].name = info[1];
            answer.push_back(info[1]+"님이 들어왔습니다.");
            inout.push_back(1);
            map[info[0]].list.push_back((int)answer.size()-1);
        }else if(record[i][0]=='L'){
            info = findUser(record[i].substr(6));
            answer.push_back(map[info[0]].name+"님이 나갔습니다.");
            map[info[0]].list.push_back((int)answer.size()-1);
            map[info[0]].in = false;
            inout.push_back(0);
        }else if(record[i][0]=='C'){
            info = findUser(record[i].substr(7));
            for(int i=0; i<map[info[0]].list.size();i++){
                int idx = map[info[0]].list[i];
                if(inout[idx]==1){
                    answer[idx]= info[1]+"님이 들어왔습니다.";
                }else{
                    answer[idx]= info[1]+"님이 나갔습니다.";
                }
            }
            
        }
    }
    
    return answer;
}


int main(){
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1237 ssssss");
    record.push_back("Enter uid1234 bb");
    record.push_back("Leave uid1234");
    record.push_back("Change uid1237 Ryanssssss");
    vector<string> vc = solution(record);
    for(int i=0; i<vc.size();i++){
        cout<<vc[i]<<endl;
    }
}



