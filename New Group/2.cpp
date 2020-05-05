//
//  2.cpp
//  backjoon
//
//  Created by 조연희 on 21/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;




/*
 * Complete the 'segment' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER x
 *  2. INTEGER_ARRAY arr
 */
struct Node{
    int v;
    int t;
    Node(int v, int t):v(v),t(t){}
};
struct NodeCmp{
    bool operator()(Node n1, Node n2){
        if(n1.v < n2.v){
            return false;
        }else{
            return true;
        }
    }
};
priority_queue<Node, vector<Node>,NodeCmp> pq;
int segment(int x, vector<int> arr) {
    vector<int> ans;
    int max=0;
    for(int i=0; i<x-1;i++){
        pq.push(Node(arr[i],i));
    }
    for(int i=x-1; i<arr.size();i++){
        pq.push(Node(arr[i],i));
        while(!pq.empty() &&(i - pq.top().t >=x)){
            pq.pop();
        }
        if(max > pq.top().v){
            max = pq.top().v;
        }
    }
    
}

int main(){
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    
    segment(2,temp);
}

