#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int t1;
    int d1;
};
Node arr[1000000];
int T,n;
bool comp(Node a, Node b) {
    return a.d1 > b.d1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int t=1; t<=T;t++){
        cin>>n;
        for(int i=0; i<n;i++){
            cin>>arr[i].t1>>arr[i].d1;
        }
        sort(arr, arr+n,comp);
        int lastDay = arr[0].d1;
        for(int i=0; i<n;i++){
            lastDay = (lastDay -arr[i].t1 < arr[i].d1 - arr[i].t1?lastDay-arr[i].t1:arr[i].d1-arr[i].t1);
                
        }
        cout<<"#"<<t<<" "<<lastDay<<'\n';
    }
}
