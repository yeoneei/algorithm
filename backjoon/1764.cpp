//
//  1764.cpp
//  backjoon
//
//  Created by 조연희 on 10/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,k;
string str;
vector<string> temp;
map<string,int> maa;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>m>>k;
    cin.ignore();
    for(int i=0; i<m;i++){
        cin>>str;
        maa[str]++;
    }
    for(int i=0; i<k;i++){
        cin>>str;
        if(maa[str]!=0){
            temp.push_back(str);
        }
    }
    sort(temp.begin(),temp.end());
    cout<<temp.size()<<'\n';
    for(int i=0; i<temp.size();i++){
        cout<<temp[i]<<'\n';
    }
}
