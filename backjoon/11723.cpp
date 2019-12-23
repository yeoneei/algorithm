//
//  11723.cpp
//  backjoon
//
//  Created by 조연희 on 15/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int sum=0;
char s[10];
int val;
int main(){
    int T;
    scanf("%d",&T);
    for(int tc=0; tc<T;tc++){
        scanf("%s",&s);
        scanf("%d", &val);
        
        if(s[0]=='a' && s[1]=='d') sum |=(1<<val);
        else if(s[0]=='r'){
            sum = sum & ~(1<<val);
        }
        else if(s[0]=='c'){
            if((sum & (1<<val)) >0) cout<<1<<endl;
            else cout<<0<<endl;
        }
        else if(s[0]=='t'){
            bool check = sum & (1<<val);
            if(check==true){
                sum = sum & ~(1<<val);
            }else{
                sum = sum | (1<<val);
            }
        }
        else if(s[0]=='a') sum  =(1<<21)-1;
        else {
            sum=0;
        }
    }
}
