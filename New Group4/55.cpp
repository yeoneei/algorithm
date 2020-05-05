//
//  55.cpp
//  backjoon
//
//  Created by 조연희 on 25/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ar[12]={31,28,31,30,31,30,31,31,30,31,30,31};
vector<int>day;
void getDay(string temp){
    string month = "";
    month+=temp[5];
    month+=temp[6];
    int m = stoi(month.c_str());

    string da = "";
    da+=temp[8];
    da+=temp[9];
    int d = stoi(da.c_str());
    string don="";
    for(int i=11; i<temp.size();i++){
        don+=temp[i];
    }
    int money = stoi(don.c_str());
    int dd=0;
    for(int i=0; i<m-1;i++){
        dd+=ar[i];
    }
    dd+=d;
    for(int i =dd-1; i<dd-1+30;i++){
        day[i]+=money;
    }
}


vector<int> solution(vector<string> purchase) {
    day.clear();
    day.resize(365);
    
    for(int i=0; i<purchase.size();i++){
        getDay(purchase[i]);
    }
    
    vector<int> answer;
    answer.resize(5);
    for(int i=0; i<365;i++){
        int p= day[i];
        if(p>=0 && p<10000)answer[0]++;
        else if(p>=10000 && p<20000)answer[1]++;
        else if(p>=20000 && p<50000)answer[2]++;
        else if(p>=50000 && p<100000)answer[3]++;
        else answer[4]++;
    }
    
    
    return answer;
}

int main(){
    vector<string> list = {"2019/01/30 5000", "2019/04/05 10000", "2019/06/10 20000", "2019/08/15 50000", "2019/12/01 100000"};
    solution(list);
}
