//
//  10610.cpp
//  backjoon
//
//  Created by 조연희 on 09/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string a;
vector<char> v;
int sum=0;
bool c=false;
int main(){
    cin>>a;
    for(int i=0; a[i];i++){
        if(a[i]=='0'){
            c=true;
        }
        sum+=(int)(a[i]-'0');
        
    }
    if(!c  || sum%3!=0){
        cout<<-1;
        return 0;
    }else{
        sort(a.begin(), a.end());
        for(int i=(int)a.size()-1; a[i];i--){
            cout<<a[i];
        }
        
    }
    
}

