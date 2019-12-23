#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

vector<string> input;
char map[4][4];
bool check[300000];
int n,m;

void dfs(string find,int idx,int x, int y,int stringIdx){
    if(idx==find.size()-1 && map[y][x]==find.at(find.size()-1)){
        check[stringIdx]=1;
        return;
    }
    if(idx>=find.size()-1){
        return;
    }
    for(int i=0; i<8;i++){
        int ny = y+ dy[i];
        int nx = x+ dx[i];
        if(nx <0 || nx>=4 || ny<0 || ny>=4) continue;
        if(map[ny][nx]==find.at(idx+1)){
            dfs(find,idx+1,nx,ny,stringIdx);
        }
    }
    
}
void init(){
    for(int i=0; i<n;i++){
        check[i]=0;
    }
}

bool dictionaryCheck(string a, string b){
    int idx=0;
    int size = (a.size()>b.size()? b.size():a.size());
    for(;idx<size;idx++){
        if(a.at(idx)<b.at(idx)){
            return true;
        }else if(a.at(idx)>b.at(idx)){
            return false;
        }
    }
    return (a.size()<b.size()?true:false);
}

int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        string a;
        cin>>a;
        input.push_back(a);
    }
    cin>>m;
    for(int i=0; i<m;i++){
        init();
        int max=0;
        int maxIdx=0;
        int score=0;
        int count=0;
        for(int j=0; j<4;j++){
            for(int k=0; k<4;k++){
                cin>>map[j][k];
            }
        }
        
        for(int j=0; j<n;j++){
            for(int yy = 0; yy<4;yy++){
                if(check[j]==1){
                    break;
                }
                for(int xx=0; xx<4;xx++){
                    if(check[j]==1){
                        break;
                    }
                    if(map[yy][xx]==input[j].at(0)){
                        dfs(input[j],0,xx,yy,j);
                    }
                }
            }
            if(check[j]==1 && max < input[j].size()){
                maxIdx= j;
                max = (int)input[j].size();
            }
            if(check[j]==1 && input[maxIdx].size() == input[j].size()){
                if(dictionaryCheck(input[j], input[maxIdx])==true){
                    maxIdx=j;
                }
                
            }
            
            if(check[j]==1){
                count++;
                int size = (int)input[j].size();
                if(size==3 || size==4){
                    score+=1;
                }
                if(size==5 ){
                    score+=2;
                }
                if(size==6){
                    score+=3;
                }
                if(size==7){
                    score+=5;
                }
                if(size==8){
                    score+=11;
                }
            }
            
        }
        cout<<score<<" "<<input[maxIdx]<<" "<<count<<endl;
    }
}
