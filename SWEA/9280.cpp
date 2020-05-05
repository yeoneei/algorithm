//
//  9280.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T,n,m,temp;
vector<int> ar;
vector<int> car;
vector<int> carCheck;

int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        ar.clear();
        car.clear();
        carCheck.clear();
        cin>>n>>m;
        ar.resize(n);
        car.resize(m);
        carCheck.resize(m+1);
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0; i<n;i++){
            cin>>ar[i];
            pq.push(i);
        }
        for(int i=0; i<m;i++){
            cin>>car[i];
        }
        int time = 2*m;
        queue<int> ready;
        long long sum=0;
        while(time--){
            cin>>temp;
            if(!pq.empty() && !ready.empty()){
                int t = min((int)pq.size(), (int)ready.size());
                while(t--){
                    carCheck[ready.front()-1]=pq.top();
                    sum += ar[pq.top()]*car[ready.front()-1];
                    cout<<temp<<" : "<<car[ready.front()-1]<<" "<<ar[pq.top()]<<endl;
                    pq.pop();ready.pop();
                    
                }
            }
            
            if(temp<0){
                temp = -1*temp;
                int num = carCheck[temp-1];
                carCheck[temp-1]=0;
                pq.push(num);
                continue;
            }
            
            if(temp>0){
                if(pq.empty()){
                    ready.push(temp);
                    continue;
                }
                //차가 들어옴
                cout<<temp<<" : "<<car[temp-1]<<" "<<ar[pq.top()]<<endl;
                carCheck[temp-1]=pq.top();
                sum+=ar[pq.top()]*car[temp-1];
                pq.pop();
            }
        }
        cout<<"#"<<tc<<" "<<sum<<'\n';
    }
}
