#include <iostream>
#include <queue>
#define N 1000
#define INF 98765432;
using namespace std;

int map[N+1][N+1];
int transferNum[N+1];
bool transfer[N+1];
int dist[N+1];
bool check[N+1];
int endNum;
int n;
int resultC=INF;
int resultSum=0;
struct Node{
    int c;
    int v;
    Node(int c, int v):c(c),v(v){}
};
struct Cmp{
    bool operator()(Node n1, Node n2){
        if(n1.c > n2.c){
            return true;
        }else if(n1.c < n2.c){
            return false;
        }else{
            if(n1.v > n2.v){
                return true;
            }else{
                return false;
            }
        }
    }
};
priority_queue<Node, vector<Node>,Cmp> pq;
void dijkstra(){
    dist[0]=0;
    int min=INF;
    int v=0;
    
    for(int i=0; i<n;i++){
        min = INF;
        for(int j=0; j<n;j++){
            if(check[j]==0 && min > dist[j]){
                min = dist[j];
                v=j;
            }
        }
        check[v]=1;
        for(int j=0; j<n;j++){
            
            if (dist[j] > dist[v] + map[v][j])
            {
                dist[j] = dist[v] + map[v][j];
                if(transfer[v]!=transfer[j]){
                    transferNum[j] = transferNum[v]+1;
                }
                if(endNum==j){
                    pq.push(Node(transferNum[j],dist[j]));
                }
                
            }
        }
    }
}

int main(){
    cin>>n>>endNum;
    for(int i=0; i<n;i++){
        cin>>transfer[i];
        dist[i]=INF;
        check[i]=0;
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==0) map[i][j]=INF;
        }
    }
    dijkstra();
    cout<<pq.top().c<<" "<<pq.top().v<<endl;
    
}
