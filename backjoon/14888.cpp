//
//  14888.cpp
//  backjoon
//
//  Created by 조연희 on 12/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[11];
int op[4];
vector<string> answer;
vector<int> last;
void dfs(int cnt, string cmp){
    if(cnt== n-1){
        answer.push_back(cmp);
        return;
    }
    
    for(int i=0; i<4;i++){
        if(op[i]==0) continue;
        op[i]--;
        cmp+=(i+'0');
        dfs(cnt+1, cmp);
        op[i]++;
        cmp = cmp.substr(0, cmp.size()-1);
        
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    for(int i=0; i<4;i++){
        cin>>op[i];
    }
    
    dfs(0,"");
    
    for(int i=0; i<answer.size();i++){
        int sum=0;
        int idx=0;
        sum= arr[idx++];
        for(int j=0; j<answer[i].size();j++){
            switch (answer[i][j]-'0') {
                case 0:
                    sum = sum+ arr[idx++];
                    break;
                case 1:
                    sum = sum - arr[idx++];
                    break;
                case 2:
                    sum = sum * arr[idx++];
                    break;
                case 3:
                    sum = sum / arr[idx++];
                    break;
                default:
                    break;
            }
        }
        last.push_back(sum);
    }
    sort(last.begin(), last.end());
    cout<<last.at(last.size()-1)<<endl;
    cout<<last.at(0)<<endl;
    
}
