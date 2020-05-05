//
//  6.cpp
//  backjoon
//
//  Created by 조연희 on 05/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    string name;
    vector<TreeNode *>children;
};

TreeNode *node;
void madeFilePaht(string path){
    TreeNode *now = node;
    string temp="";
    for(int i=1; i<path.size();i++){
        if(path[i]=='/'){
            for(int j=0; j<now->children.size();j++){
                if(now->children[j]->name==temp){
                    now = now->children[j];
                    break;
                }
            }
            temp="";
        }else{
            temp+=path[i];
        }
    }
    TreeNode *newOne = new TreeNode();
    newOne->name = temp;
    now->children.push_back(newOne);
}


void madeFile(string path){
    string temp="";
    TreeNode *now = node;
    for(int i=1; i<path.size();i++){
        if(path[i]=='/'){
            for(int j=0; j<now->children.size();j++){
                if(now->children[j]->name==temp){
                    now = now->children[j];
                    break;
                }
            }
            temp="";
        }else{
            temp+=path[i];
        }
    }
    
    TreeNode *newOne = new TreeNode();
    newOne->name = temp;
    now->children.push_back(newOne);
}

void removeFile(string path){
    string temp="";
    TreeNode *now = node;
    for(int i=7; i<path.size();i++){
        if(path[i]=='/'){
            for(int j=0; j<now->children.size();j++){
                if(now->children[j]->name==temp){
                    now = now->children[j];
                    break;
                }
            }
            temp="";
        }else{
            temp+=path[i];
        }
    }
    for(int i=0; i<now->children.size();i++){
        if(temp==now->children[i]->name){
            now->children.erase(now->children.begin()+i);
        }
    }
}

void cpFile(string command){
    int i=0;
    string source="";
    string dest="";
    string temp="";
    for( ;i<command.size();i++){
        if(command[i]=='/'){
            temp ="";
        }else if(command[i]==' '){
            source=temp;
            temp="";
        }else temp+=command[i];
    }
    dest = temp;
    temp="";
    
    TreeNode *now = node;
    for(int i=0; i<source.size();i++){
        if(source[i]=='/'){
            for(int j=0; j<now->children.size();j++){
                if(now->children[j]->name==temp){
                    now = now->children[j];
                    break;
                }
            }
            temp="";
        }else{
            temp+=source[i];
        }
    }
    TreeNode *cp;
    for(int i=0; i<now->children.size();i++){
        if(now->children[i]->name == temp){
            cp = now->children[i];
        }
    }
    now = node;
    for(int i=1; i<dest.size();i++){
        if(dest[i]=='/'){
            for(int j=0; j<now->children.size();j++){
                if(now->children[j]->name==temp){
                    now = now->children[j];
                    break;
                }
            }
            temp="";
        }else{
            temp+=dest[i];
        }
    }
    for(int i=0; i<dest.size();i++){
        if(now->children[i]->name==temp){
            now->children[i]=cp;
        }
    }
    
    
}


vector<string> answer;

void treedfs(string s,TreeNode * now){
    s+="/"+now->name;
    answer.push_back(s);
    for(int i=0; i<now->children.size();i++){
        treedfs(s, now->children[i]);
    }
    
}



vector<string> solution(vector<string> directory, vector<string> command) {
    node = new TreeNode();
    for(int i=0; i<directory.size();i++){
        if (directory[i]=="/") {
            continue;
        }
        string dir = directory[i];
        madeFilePaht(dir);
    }
    
    /*
    for(int i=0; i<command.size();i++){
        if(command[i][0]=='m'){
            madeFile(command[i]);
        }else if(command[i][0]=='c'){
            cpFile(command[i]);
        }else if(command[i][0]=='r'){
            removeFile(command[i]);
        }
    }
     */
    //트리순회
    treedfs("",node);
    sort(answer.begin(),answer.end());
    vector<string> ans;
    for(int i=0; i<answer.size();i++){
        ans.push_back(answer[i]);
    }
    return ans;
}

int main(){
    vector<string> dir = {
                          "/",
                          "/hello",
                          "/hello/tmp",
                          "/root",
                          "/root/abcd",
                          "/root/abcd/etc",
                          "/root/abcd/hello"
    };
    vector<string> cm = {
        "mkdir /root/tmp",
        "cp /hello /root/tmp",
        "rm /hello"
    };
    vector<string> answer = solution(dir, cm);
    for(int i=0; i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
}
