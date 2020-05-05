//
//  1358.cpp
//  backjoon
//
//  Created by 조연희 on 24/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> mset;
string temp;
int total=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    while(getline(cin,temp)){
        mset[temp]++;
        total++;
    }
    cout.precision(4);
    cout<<fixed;
    for(auto ele:mset) cout<<ele.first<<" "<<((double)ele.second/total)*100<<'\n';
}
