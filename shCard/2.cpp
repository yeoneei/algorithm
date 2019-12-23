//
//  2.cpp
//  backjoon
//
//  Created by 조연희 on 11/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#define HASH 1007
using namespace std;

int n,m;
bool check[1007][1007];
int countC[1007];
vector<string> vList;
vector<int> hashV;
int hashF(string key){
    int result = 1;
    int value = 107;
    for(int i=0; i<key.size();i++){
        result = (result + (key[i]*value)%HASH)%HASH;
    }
    return result;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        string temp;
        cin>>temp;
        vList.push_back(temp);
        hashV.push_back(hashF(temp));
    }
    
    string a,b;
    for(int i=0; i<m;i++){
        cin>>a>>b;
        check[hashF(a)][hashF(b)]=1;
        check[hashF(b)][hashF(a)]=1;
        countC[hashF(a)]++;
        countC[hashF(b)]++;
    }
    
    int maxC=0;
    for(int i=0; i<hashV.size();i++){
        if(maxC < countC[hashV[i]]){
            maxC = countC[hashV[i]];
        }
    }
    
    int result[2];
    int idxCount=0;
    for(int i=0;i<hashV.size();i++){
        if(countC[hashV[i]]==maxC){
            result[idxCount++]= i;
            cout<<vList[i]<<" ";
        }
    }
    cout<<endl;
    int count=0;
    for(int i=0; i<hashV.size();i++){
        if(check[hashV[result[0]]][hashV[i]]==1 && check[hashV[result[1]]][hashV[i]]==1){
            count++;
        }
    }
    cout<<count<<endl;
}
