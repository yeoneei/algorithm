#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,a,b;
long long now, dist;
vector<pair<int,int>>input;
priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int, int>>> pq;
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>a>>b;
        input.push_back(make_pair(a,b));
    }
    cin>>dist>>now;
    
    sort(input.begin(),input.end());
    
    int cnt=0;
    int i=0;
    while(now<dist){
        
        while(input[i].first<=now && i<input.size()){
            pq.push(make_pair(input[i].second, input[i].first));
            i++;
        }
        if(pq.empty())break;
        
        now+=pq.top().first;
        pq.pop();
        cnt++;
    }
    
    if(now>=dist){
        cout<<cnt;
    }else{
        cout<<-1;
    }
    
}
