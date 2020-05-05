//
//  2.cpp
//  backjoon
//
//  Created by 조연희 on 29/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string toLower(string t){
    for(int i=0; i<t.size();i++){
        if('A'<=t[i] && t[i]<='Z'){
            t[i] =t[i]-'A'+'a';
        }
        if(t[i]=='-'){
            t.erase(t.begin()+i);
            i--;
            continue;
        };
    }
    return t;
}
map<string,bool> m;
string getAnswer(string temp,string C){
    if(temp[0]==' ') temp.erase(temp.begin());
    vector<string> name;
    string n="";
    for(int t=0; t<temp.size();t++){
        if(temp[t]==' '){
            name.push_back(n);
            n="";
            continue;
        }
        n+=temp[t];
    }
    name.push_back(n);
    string answer="";
    if(name.size()==3){
        answer+=toLower(name[2]);
    }else{
        answer+=toLower(name[1]);
    }
    answer+='_';
    answer+=toLower(name[0]);
    int cnt=2;
    bool c=false;
    string get = answer;
    while(m[get]){
        c=true;
        get = answer+ to_string(cnt);
        cnt++;
    }
    if(c){
        answer = answer + to_string(cnt-1);
    }
    m[answer]=1;
    answer+='@';
    answer+=toLower(C);
    answer+=".com";
    return temp+" <"+answer+">";
    
}

string solution(string &S, string &C) {
    // write your code in C++14 (g++ 6.2.0)
    string answer="";
    string temp="";
    for(int i=0; i<S.size();i++){
        if(S[i]==';'){
            string an = getAnswer(temp,C);
            if(answer.size()==0)answer+=an;
            else answer+="; "+an;
            temp="";
            continue;
        }
        temp+=S[i];
    }
    
    string an = getAnswer(temp, C);
    answer+="; "+an;
    return answer;
}

string test  = "John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter Brian Parker";
string test2= "Example";
int main(){
    
    cout<<solution(test,test2);
}

