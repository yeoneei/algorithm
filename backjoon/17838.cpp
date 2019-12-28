//
//  17838.cpp
//  backjoon
//
//  Created by 조연희 on 28/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int T;
string str;
int main(){
    cin>>T;
    cin.ignore();
    while(T--){
        getline(cin,str);
        if(str.length()!=7){
            printf("0\n");
            continue;
        }
        if(str[0]==str[1] && str[0]==str[4] && str[0]!=str[2] && str[2]==str[3] && str[2]==str[5] && str[2]==str[6]){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
}
