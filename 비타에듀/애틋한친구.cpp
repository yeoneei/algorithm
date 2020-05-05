//
//  애틋한친구.cpp
//  backjoon
//
//  Created by 조연희 on 18/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    long long s;
    long long d;
    Node(long long s, long long d):s(s),d(d){}
};

long long getDistance(Node n1, Node n2){
    return (n1.s - n2.s)*(n1.s - n2.s) + (n1.d - n2.d)*(n1.d - n2.d);
}
int n,s,d;
vector<Node> vc;
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>s>>d;
        vc.push_back(Node(s,d));
    }
    long long distance=0;
    int idxS=0;
    int idxD=0;
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n;j++){
            long long temp = getDistance(vc[i], vc[j]);
            if(distance < temp){
                distance = temp;
                idxS = i;
                idxD = j;
            }
        }
    }
    cout<<idxS+1<<" "<<idxD+1<<endl;
}
