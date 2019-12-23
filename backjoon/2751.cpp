//
//  2751.cpp
//  backjoon
//
//  Created by 조연희 on 26/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[500001];
int main(){
    vector<int> v;
    int n;
    cin>>n;
    int sum=0;
    for(int i=0; i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        sum+=a;
    }
    
    sort(v.begin(),v.end());
    for(int i=0; i<n;i++){
        cout<<v.at(i)<<"\n";
    }
    
    double agv = (double)(sum)/(double)n;
    cout<< (int)(agv+0.5)<<endl;
    cout<<v.at((n/2)-1)<<endl;
    //최빈값
    
    cout<<v.at(v.size()-1)-v.at(0)<<endl;
    
    
}
