//
//  4130.cpp
//  backjoon
//
//  Created by 조연희 on 20/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <deque>
#include <queue>
#include <math.h>
using namespace std;

deque<int> dequ[4];
int n;
int k,d;
int T;
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        for(int i=0; i<4;i++){
            dequ[i].resize(8);
            for(int j=0; j<8;j++){
                cin>>dequ[i][j];
            }
        }
        for(int i=0; i<n;i++){
            cin>>k>>d;
            queue<pair<int,int>> qu;
            qu.push(make_pair(k-1,d));
            int c = -1*d;
            for(int j=k-2; j>=0;j--){
                if(dequ[j][2] !=dequ[j+1][6]){
                    qu.push(make_pair(j, c));
                    c = -1*c;
                    continue;
                }
                break;
                
            }
            c = -1*d;
            for(int j=k;j<4;j++){
                if(dequ[j][6]!=dequ[j-1][2]){
                    qu.push(make_pair(j,c));
                    c= -1*c;
                    continue;
                }
                break;
            }
            while(!qu.empty()){
                int num  = qu.front().first;
                int dir = qu.front().second;
                qu.pop();
                if(dir == 1){
                    int x = dequ[num].back();
                    dequ[num].pop_back();
                    dequ[num].push_front(x);
                }
                if(dir == -1){
                    int x = dequ[num].front();
                    dequ[num].pop_front();
                    dequ[num].push_back(x);
                }
            }
        }
        int sum=0;
        for(int i=0; i<4;i++){
            if(dequ[i][0]==1){
                sum+=pow(2,i);
            }
        }
        cout<<"#"<<tc<<" "<<sum<<endl;
    
    }
}
