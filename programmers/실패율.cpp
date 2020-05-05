//
//  실패율.cpp
//  backjoon
//
//  Created by 조연희 on 16/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int cnt[501];
struct Node{
    double value;
    int idx;
    Node(double value, int idx):value(value),idx(idx){};
};
struct Cmpt{
    bool operator()(Node n1, Node n2){
        if(n1.value > n2.value) return false;
        else if(n1.value < n2.value) return true;
        else{
            if(n1.idx < n2.idx) return false;
            else return true;
        }
    }
};

vector<int> solution(int N, vector<int> stages) {
    priority_queue<Node, vector<Node>, Cmpt> p;
    vector<int> answer;
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<stages.size();i++){
        cnt[stages[i]]++;
    }
    int pre=cnt[N+1];
    for(int i=N; i>=1; i--){
        pre+=cnt[i];
        p.push(Node(((double)cnt[i]/(double)pre),i));
    }
    while(!p.empty()){
        answer.push_back(p.top().idx);
        p.pop();
    }
    return answer;
}
int main(){
    //[2, 1, 2, 6, 2, 4, 3, 3]
    //reuslt = [3,4,2,1,5]
    vector<int> stage;
    stage.push_back(2);
    stage.push_back(1);
    stage.push_back(2);
    stage.push_back(6);
    stage.push_back(2);
    stage.push_back(4);
    stage.push_back(3);
    stage.push_back(3);
    solution(5, stage);
}
