//
//  10808.cpp
//  backjoon
//
//  Created by 조연희 on 24/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string temp;
int cnt[26];
int main(){
    getline(cin,temp);
    for(char ch : temp){
        cnt[ch-'a']++;
    }
    for(int i=0; i<26;i++){
        printf("%d ",cnt[i]);
    }
}
