//
//  7785.cpp
//  backjoon
//
//  Created by 조연희 on 10/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;
string str;
int n;
map<string,int,greater<string>> ma;

string getName(string str){
    string temp="";
    for(int i=0; i<str.size();i++){
        if(str[i]==' ')break;
        temp+=str[i];
    }
    return temp;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    cin.ignore();
    for(int i=0; i<n;i++){
        getline(cin,str);
        string name = getName(str);
        string state = str.substr(str.size()-5,5);
        if(state[0]=='e') ma[name]=1;
        if(state[0]=='l') ma[name]=0;
    }
    map<string,int>::iterator iter;
    for(iter = ma.begin(); iter !=ma.end();iter++){
        if(iter->second == 1){
            cout<<iter->first<<'\n';
        }
    }
}
