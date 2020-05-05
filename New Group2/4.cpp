//
//  4.cpp
//  backjoon
//
//  Created by 조연희 on 28/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m;

long long find(long long x){
    if(m[x]==x)return m[x];
    return m[x]=find(m[x]);
}

long long uion(long long u, long long v){
    u= find(u);
    v= find(v);
    if(u>v){
        m[v]=u;
        return u;
    }
    m[u]=v;
    return v;

}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0; i<room_number.size();i++){
        if(m[room_number[i]]==0){
            m[room_number[i]]=room_number[i];
        }
        long long doc = find(m[room_number[i]]);
        answer.push_back(doc);
        if(m[doc+1]==0){
            m[doc+1]=(doc+1);
        }
        uion(doc, doc+1);
    }
    
    return answer;
    
}
int main(){
    vector<long long> inpu1 ={1,3,4,1,3,1};
    vector<long long > ans = solution(10, inpu1);
    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
