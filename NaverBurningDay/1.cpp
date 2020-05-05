//
//  1.cpp
//  backjoon
//
//  Created by 조연희 on 27/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;


int input[9];
bool check[9];
int answer=0;
void init(){
    memset(input,0,sizeof(input));
    memset(check,0,sizeof(check));
    answer=0;
}

void dfs2(vector<int> temp, vector<string> &A){
    int c=0;
    bool fail=false;
    int maxLen=0;
    for(int i=0; i<temp.size();i++){
        if(c&input[temp[i]]){
            fail=true;
            break;
        }
        c|=input[temp[i]];
        maxLen+= (int)A[temp[i]].size();
    }
    if(fail) return;
    answer = max(maxLen,answer);
    
}

void dfs1(int size, int v, int n,vector<int> temp, vector<string>& A){
    if(size>=2 && size<=n){
        dfs2(temp,A);
    }
    for(int i=v; i<n;i++){
        if(check[i])continue;
        check[i]=1;
        temp.push_back(i);
        dfs1(size+1,i,n,temp,A);
        check[i]=0;
        temp.pop_back();
    }
}
int solution(vector<string> &A){
    vector<string> correctInput;
    bool inputCheck=true;
    for(int i=0; i<A.size();i++){
        inputCheck = true;
        for(int s=0; s<A[i].size();s++){
            if(input[i]&(1<<(A[i][s]-'a'))){
                inputCheck=false;
                break;
            }
            input[i]|=(1<<(A[i][s]-'a'));
            
        }
        
        if(!inputCheck){
            check[i]=1;
        }
    }
    vector<int> temp;
    dfs1(0,0,(int)A.size(),temp,A);
    return answer;
}

int main(){
    vector<string> A;
    A.push_back("banannaana");
    A.push_back("eeeee");
    A.push_back("ss");
    A.push_back("a");
    
    cout<<solution(A)<<endl;
}
