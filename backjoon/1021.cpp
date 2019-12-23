#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int n,m;
deque<int> dq;

int main(void)
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        dq.push_back(i+1);
    }
    
    int result=0;
    for(int i=0; i<m;i++){
        int temp;
        cin>>temp;
        
        int cur=1;
        for(deque<int>::iterator iter = dq.begin(); iter< dq.end();iter++){
            if(*iter == temp){
                break;
            }
            cur++;
        }
        int left = cur-1;
        int right = dq.size()-cur+1;
        
        if(left<right){
            for(int j=1; j<=left;j++){
                int num = dq.front();
                dq.pop_front();
                dq.push_back(num);
                result++;
            }
            dq.pop_front();
        }else{
            for(int j=1; j<=right;j++){
                int num = dq.back();
                dq.pop_back();
                dq.push_front(num);
                result++;
            }
            dq.pop_front();
        }
    }
    cout<<result<<endl;
    
}
