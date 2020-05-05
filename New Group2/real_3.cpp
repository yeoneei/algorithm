//
//  real_3.cpp
//  backjoon
//
//  Created by 조연희 on 28/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string>> vc;
    vc.resize(banned_id.size());
    for(int i=0; i<banned_id.size();i++){
        for(int j=0; j<user_id.size();j++){
            bool check=true;
            if(banned_id[i].size()!=user_id[j].size())continue;
            for(int s=0; s<banned_id[i].size();s++){
                if(banned_id[i][s]=='*')continue;
                if(banned_id[i][s]!=user_id[j][s]){
                    check=false;
                    break;
                }
            }
            if(check)vc[i].push_back(user_id[j]);
        }
    }
    
    
    
    return answer;
}
int main(){
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banner_id ={"*rodo", "*rodo", "******"};
    cout<<solution(user_id, banner_id)<<endl;
}
