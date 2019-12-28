//
//  11655.cpp
//  backjoon
//
//  Created by 조연희 on 24/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string temp;
int main(){
    getline(cin, temp);
    for(char ch : temp){
        if (ch >= 'a' && ch <= 'm') {
            ch = ch + 13;
        } else if (ch >= 'n' && ch <= 'z') {
            ch = ch - 13;
        } else if(ch >= 'A' && ch <= 'M') {
            ch = ch + 13;
        } else if(ch >= 'N' && ch <= 'Z') {
            ch = ch - 13;
        }
        cout<<ch;
    }
}
