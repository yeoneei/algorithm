//
//  6996.cpp
//  backjoon
//
//  Created by 조연희 on 16/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int n;
string a,b;
int arr[26];
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0;j<26;j++){
            arr[j]=0;
        }
        cin>>a;
        cout<<a<<" & ";
        cin>>b;
        cout<<b<<" are";
        if(a.size() != b.size()){
            cout<<" NOT anagrams."<<endl;
            continue;
        }
        for(int i=0; i<(int)a.size();i++){
            arr[(int)(a.at(i)-'a')]++;
            arr[(int)(b.at(i)-'a')]++;
        }
        bool check = true;
        for(int i=0; i<26;i++){
            if(arr[i]%2!=0){
                check= false;
                break;
            }
        }
        if(check){
            cout<<" anagrams."<<endl;
        }else{
            cout<<" NOT anagrams."<<endl;
        }
        
    }
}
