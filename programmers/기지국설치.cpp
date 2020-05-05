//
//  기지국설치.cpp
//  backjoon
//
//  Created by 조연희 on 19/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int last =1;
    int size = w*2+1;
    for(int i=0; i<stations.size();i++){
        int temp = stations[i]-w-last;
        if(temp<0){
            last = stations[i]+w+1;
            continue;
        }
        answer += (temp/size);
        if(temp%size!=0){
            answer++;
        }
        last = stations[i]+w+1;
    }
    if(last <=n){
        int temp = n - last+1;
        answer += (temp/size);
        if(temp%size!=0){
            answer++;
        }
    }
    return answer;
}
int main(){
    vector<int> in;
    in.push_back(4);
    in.push_back(11);
    cout<<solution(11, in, 1)<<endl;
}
