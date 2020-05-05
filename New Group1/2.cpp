//
//  2.cpp
//  backjoon
//
//  Created by 조연희 on 14/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int arr[10]={6,2,5,5,4,5,6,3,7,6};
int n;
vector<int> list;
struct CMP{
    bool operator()(string a, string b){
        if(a.size() < b.size())return true;
        else if(a.size() > b.size())return false;
        else {
            for(int s=0; s<a.size(); s++){
                if(a[s] > b[s])return true;
                else if( a[s]<b[s])return false;
            }
        }
        return true;
    }
};
priority_queue<string,vector<string>,CMP> qu;
void dfs(int value){
    if(value>n)return;
    if(value==n){
        vector<int> temp = list;
        sort(temp.begin(),temp.end());
        string ans ="";
        for(int i=temp.size()-1 ;i>=0;i--){
            ans += to_string(temp[i]);
        }
        qu.push(ans);
        return;
    }
    for(int i=0; i<10;i++){
        if(value==0 && i==0)continue;
        if(value+arr[i]>n)continue;
        list.push_back(i);
        dfs(value+arr[i]);
        list.pop_back();
    }
    
}

int main(){
    cin>>n;
    if(n>7)
    dfs(0);
    cout<<qu.top();
}
