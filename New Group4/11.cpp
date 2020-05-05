//
//  11.cpp
//  backjoon
//
//  Created by 조연희 on 25/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
string lng[6]={"C", "Java", "JavaScript", "Python3"};
map<string,map<string,map<int,int>>> m;
map<string,int> check;
map<string,map<string,int>> m2;


int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
    int answer = -1;
    
    m.clear();
    check.clear();
    m2.clear();
    
    int size = ip_addrs.size();
    for(int i=0; i<size;i++){
        check[ip_addrs[i]]++;
        if(langs[i]=="C" ||langs[i]=="C++" ||langs[i]=="C#" ){
            m2[ip_addrs[i]]["C"]++;
            m[ip_addrs[i]]["C"][scores[i]]++;
        }else{
            m2[ip_addrs[i]][langs[i]]++;
            m[ip_addrs[i]][langs[i]][scores[i]]++;
        }
    }
    int ans=0;
    map<string,int>::iterator iter;
    for(iter=check.begin();iter != check.end();iter++){
        int cnt = iter->second;
        
        bool bu=false;
        if(cnt==4){
            ans+=4;
            continue;
        }
        
        if(cnt==3 ||cnt==4){
            map<string,int> temp = m2[iter->first];
            for(int i=0; i<6;i++){
                if(temp[lng[i]]==3){
                    ans+=3;
                    bu=true;
                    break;
                }
            }
            if(bu)continue;
            
        }
        if(cnt==2 ||cnt==3 || cnt==4){
            map<string,map<int,int>> temp = m[iter->first];
            for(int i=0; i<6;i++){
                if(bu)break;
                map<int,int>::iterator iter2 = temp[lng[i]].begin();
                for( ; iter2!=temp[lng[i]].end();iter2++){
                    if(iter2->second==2){
                        ans+=2;
                        bu = true;
                        break;
                    }
                }
            }
        }
       
    }

    
    
    return size-ans;
}

int main(){
    vector<string> ip = {"5.5.5.5", "155.123.124.111", "10.16.125.0", "155.123.124.111", "5.5.5.5", "155.123.124.111", "10.16.125.0", "10.16.125.0"};
    
    vector<string> lan = {"Java", "C++", "Python3", "C#", "Java", "C", "Python3", "JavaScript"};
    vector<int>se={294, 197, 373, 45, 294, 62, 373, 373};
    
    cout<<solution(ip, lan, se)<<endl;
}
