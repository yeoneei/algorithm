//
//  1856.cpp
//  backjoon
//
//  Created by 조연희 on 18/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int n,m;
string ans;
int ansBit;
vector<string> input;
vector<int> inputBit;
int main(){
    cin>>n>>m;
    cin.ignore();
    cin>>ans;
    for(int i=0; i<ans.size();i++){
        ansBit|=1<<(ans[i]-'a');
    }
    cout<<bitset<32>(ansBit)<<endl;
    input.resize(n);
    inputBit.resize(n);
    int zero = 0;
    for(int i=0; i<n;i++){
        cin>>input[i];
        for(int j=0; j<input[i].size();j++){
            inputBit[i]|= 1<<(input[i][j]-'a');
        }
        if((ansBit&inputBit[i])==inputBit[i]){
            cout<<input[i]<<endl;
            zero|=inputBit[i];
        }
        
    }
    cout<<bitset<32>(zero)<<endl;
    ansBit^=zero;
    int cnt=0;
    cout<<bitset<32>(ansBit)<<endl;
    for(int i=0; i<26;i++){
        int temp= (1<<i);
        if((ansBit&temp)==temp){
            char ch = (char)(i+'a');
            for(int j=0; j<ans.size();j++){
                if(ans[j]==ch){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
}
