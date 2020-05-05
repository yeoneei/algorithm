//
//  4.cpp
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

map<string,string> m;

string add(string num1, string num2){
    int ca = 0;
    int sum=0;
    int size1 = num1.size()-1;
    int size2 = num2.size()-1;
    int size = min(size1, size2)+1;
    string result = "";
    while(size--){
        sum = (int)(num1[size1--]-'0')+(int)(num2[size2--]-'0')+ca;
        if(sum>=10){
            ca=1;
            sum-=10;
        }else{
            ca=0;
        }
        result = (char)(sum+'0')+result;
    }
    if(num1.size()==num2.size() && ca == 1){
        result = '1'+result;
    }else if(num1.size() > num2.size()){
        while(size1>=0){
            sum = (int)(num1[size1--]-'0')+ca;
            if(sum>=10){
                ca=1;
                sum-=10;
            }else{
                ca=0;
            }
            result = (char)(sum+'0')+result;
        }
        
    }else if(num1.size() < num2.size()){
        while(size2>=0){
            sum = (int)(num1[size2--]-'0')+ca;
            if(sum>=10){
                ca=1;
                sum-=10;
            }else{
                ca=0;
            }
            result = (char)(sum+'0')+result;
        }
    }
    //사이즈가 같을때 ca 마지막꺼처리도 해야함
    return result;
}

string sub(string num1, string num2){
    int ca = 0;
    int sum=0;
    int size1 = num1.size()-1;
    int size2 = num2.size()-1;
    int size = min(size1, size2)+1;
    string result = "";
    while(size--){
        sum = (int)(num1[size1--]-'0')-(int)(num2[size2--]-'0')+ca;
        if(sum<0){
            ca=-1;
            sum+=10;
        }else{
            ca=0;
        }
        result = (char)(sum+'0')+result;
    }
    if(num1.size() > num2.size()){
        while(size1>=0){
            sum = (int)(num1[size1--]-'0')+ca;
            if(sum<0){
                ca=-1;
                sum+=10;
            }else{
                ca=0;
            }
            result = (char)(sum+'0')+result;
        }
        
    }else if(num1.size() < num2.size()){
        while(size2>=0){
            sum = (int)(num1[size2--]-'0')+ca;
            if(sum<0){
                ca=-1;
                sum+=10;
            }else{
                ca=0;
            }
            result = (char)(sum+'0')+result;
        }
    }
    //앞에 0이 올경우 제거
    while(1){
        if(result[0]=='0'){
            result = result.substr(1);
        }else{
            break;
        }
    }
    //사이즈가 같을때 ca 마지막꺼처리도 해야함
    return result;
}


bool Cmp(vector<string> s1, vector<string> s2){
    return s1[0] < s2[0];
}
vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
    m.clear();
    vector<vector<string>> answer;
    for(int i=0; i<snapshots.size();i++){
        m[snapshots[i][0]]=snapshots[i][1];
    }
    sort(transactions.begin(),transactions.end(),Cmp);
    transactions.erase(unique(transactions.begin(), transactions.end()),transactions.end());
    
    for(int i=0; i<transactions.size();i++){
        if(transactions[i][1]=="SAVE"){
            if(m.count(transactions[i][2])==0){
                m[transactions[i][2]]="0";
            }
            string value = transactions[i][3];
            value = add(value,m[transactions[i][2]]);
            m[transactions[i][2]]=value;
        }else if(transactions[i][1]=="WITHDRAW"){
            m[transactions[i][2]] = sub(m[transactions[i][2]],transactions[i][3]);
        }
    }
    map<string,string>::iterator iter= m.begin();
    for(;iter != m.end();iter++){
        vector<string> temp;
        temp.push_back(iter->first);
        temp.push_back(iter->second);
        answer.push_back(temp);
    }
    return answer;
}

int main(){
    vector<vector<string>> st={
        {"ACCOUNT1", "500"},
        {"ACCOUNT2", "150"},
        {"ACCOUNT10", "150"}
    };
    
    vector<vector<string>> tran = {
        {"1", "SAVE", "ACCOUNT2", "1100"},
        {"2", "WITHDRAW", "ACCOUNT1", "500"},
        {"1", "SAVE", "ACCOUNT2", "1100"},
        {"4", "SAVE", "ACCOUNT3", "500"},
        {"3", "WITHDRAW", "ACCOUNT2", "30"}
    };
    vector<vector<string>> asn = solution(st, tran);
    for(int i=0; i<asn.size();i++){
        cout<<asn[i][0]<<" "<<asn[i][1]<<endl;
        
    }
        
    
    
}
