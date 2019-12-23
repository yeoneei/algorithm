//
//  7568.cpp
//  backjoon
//
//  Created by 조연희 on 14/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ps{
    int h;
    int w;
    ps(int h ,int w):h(h),w(w){}
};

vector<ps> v;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        int x, y;
        cin>>x>>y;
        v.push_back(ps(x,y));
    }
    
    for(int i=0; i<n;i++){
        int count=0;
        for(int j=0; j<v.size();j++){
            if(i==j) continue;
            if( v[j].h > v[i].h  && v[j].w > v[i].w){
                count++;
            }
        }
        cout<<count+1<<" ";
    }
    
}
