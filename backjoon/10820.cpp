//
//  10820.cpp
//  backjoon
//
//  Created by 조연희 on 24/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string temp;
int a,b,c,d;
int main(){
    while(getline(cin,temp)){
        a=0;b=0;c=0;d=0;
        for(char ch : temp){
            if('A'<=ch && ch<='Z')b++;
            else if('a'<= ch && ch <='z') a++;
            else if(ch==' ')d++;
            else if('0'<= ch && ch<='9')c++;
        }
        printf("%d %d %d %d\n",a,b,c,d);
    }
}
