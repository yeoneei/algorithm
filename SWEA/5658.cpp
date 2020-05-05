//
//  5658.cpp
//  backjoon
//
//  Created by 조연희 on 25/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int T;
int n,k;
deque<char> de;
vector<long long> vc;

void findNumber(){
    int size = n/4;
    for(int i=0; i<de.size();i+=size){
        long long r=0;
        for(int j=i; j<i+size;j++){
            char ch = de[j];
            r*=16;
            if(ch>='0' && ch<='9'){
                r+=(int)(de[j]-'0');
            }else if(ch=='A'){
                r+=10;
            }else if(ch=='B'){
                r+=11;
            }else if(ch=='C'){
                r+=12;
            }else if(ch=='D'){
                r+=13;
            }else if(ch=='E'){
                r+=14;
            }else if(ch=='F'){
                r+=15;
            }
        }
    
        vc.push_back(r);
    }
    
}
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n>>k;
        vc.clear();
        de.resize(n);
        for(int i=0; i<n;i++){
            cin>>de[i];
        }
        int time =n/4;
        while(time--){
            findNumber();
            int x = de.back();
            de.pop_back();
            de.push_front(x);
        }
        
        sort(vc.begin(),vc.end(),greater<int>());
        vc.erase(unique(vc.begin(),vc.end()),vc.end());
        cout<<"#"<<tc<<" "<<vc[k-1]<<endl;
        
    }
}
