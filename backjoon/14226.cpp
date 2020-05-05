#include <iostream>
#include <queue>
using namespace std;

int n;
int ans=2000;
struct Node{
    int cnt;
    int save;
    Node(int cnt, int save):cnt(cnt),save(save){}
};
int dist[2001][2001];
int main(){
    cin>>n;
    queue<Node> qu;
    qu.push(Node(1,0));
    while(!qu.empty()){
        int cnt = qu.front().cnt;
        int save = qu.front().save;
        if(cnt==n){
            cout<<dist[cnt][save];
            return 0;
        }
        qu.pop();
        if(cnt>0 && cnt< 2*n && dist[cnt][cnt]==0){
            dist[cnt][cnt]= dist[cnt][save]+1;
            qu.push(Node(cnt,cnt));
        }
        if(cnt+save > 0 && cnt+save <2*n && dist[cnt+save][save]==0){
            dist[cnt+save][save] = dist[cnt][save]+1;
            qu.push(Node(cnt+save,save));
        }
        if(cnt-1 >0 && cnt-1 < 2*n && dist[cnt-1][save]==0){
            dist[cnt-1][save] = dist[cnt][save]+1;
            qu.push(Node(cnt-1,save));
        }
    
    }
}
