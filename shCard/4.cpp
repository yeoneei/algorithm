//
//  4.cpp
//  backjoon
//
//  Created by 조연희 on 11/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int n,m,a,b;
int countT[26];

int main(){
    cin>>n>>m;
    string result;
    cin>>result;
    int maxC=0;
    int maxJ=0;
    for(int i=0;i<m;i++){
        for(int k=0; k<26;k++){
            countT[k]=0;
        }
        cin>>a>>b;
        maxC=0;
        maxJ=0;
        for(int j=a-1; j<b;j++){
            int base = result[j]-'A';
            countT[base]++;
            if(countT[base]>maxC){
                maxC = countT[base];
                maxJ = base;
            }
        }
        cout<<(char)(maxJ+'A')<<endl;
    }
}


