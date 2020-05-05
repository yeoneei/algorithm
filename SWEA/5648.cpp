//
//  5648.cpp
//  backjoon
//
//  Created by 조연희 on 25/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    float y;
    float x;
    int d;
    int w;
    Node(float y, float x, int d, int w):y(y),x(x),d(d),w(w){}
};

vector<Node> vc;
map<pair<float,float>,int> m;

float dy[4]={-0.5,0,0.5,0};
float dx[4]={0,-0.5,0,0.5};

int n,d,w,T;
float y,x;

int remove(vector<int>& crush){
    int sum=0;
    sort(crush.begin(),crush.end(),greater<int>());
    crush.erase(unique(crush.begin(), crush.end()),crush.end());
    for(int i=0; i<crush.size();i++){
        int idx = crush[i];
        m[make_pair(vc[idx].y, vc[idx].x)]=0;
        sum+=vc[idx].w;
        vc.erase(vc.begin()+idx);
    }
    return sum;
}

int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        vc.clear();
        vc.resize(n);
        for(int i=0; i<n;i++){
            cin>>y>>x>>d>>w;
            vc.push_back(Node(y,x,d,w));
            m[make_pair(y,x)]=i+1;
        }
        
        int t =4000;
        int answer=0;
        while(t--){
            vector<int> crush;
            for(int i=0; i<vc.size();i++){
                float y = vc[i].y;
                float x = vc[i].x;
                int d = vc[i].d;
                cout<<y<<" "<<x<<" "<<d<<endl;
                y+=dy[d];
                x+=dx[d];
                int temp = m[make_pair(y, x)];
                if(temp!=0){
                    crush.push_back(temp-1);
                    crush.push_back(i);
                }else{
                    m[make_pair(vc[i].y, vc[i].x)]=0;
                    m[make_pair(y, x)]=(i+1);
                }
            }
            answer+=remove(crush);
        }
        cout<<answer<<endl;
        
    }
}
