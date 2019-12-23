//
//  1541.cpp
//  backjoon
//
//  Created by 조연희 on 22/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<int> st;
    string line;
    getline(cin,line);

    
    size_t mi = line.find('-');
    
    for(int i=(int)mi;i<line.size();i++){
        if(line.at(i)=='+'){
            line[i]='-';
        }
    }
    
    char pre ='+';
    int result=0;
    string n="";
    for(int i=0; i<line.size();i++){
        char now = line.at(i);
        if(now == '+' || now=='-'){
            if(pre =='+'){
                int num = atoi(n.c_str());
                n="";
                result+=num;
                pre = now;
            }else {
                int num = atoi(n.c_str());
                n="";
                result-=num;
                pre = now;
            }
        }else{
            n +=now;
        }
    }
    
    if(pre == '+'){
        result += atoi(n.c_str());
    }else{
        result -=atoi(n.c_str());
    }
    cout<<result<<endl;
    
    
}
