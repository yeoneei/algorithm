//
//  5644.cpp
//  backjoon
//
//  Created by 조연희 on 02/05/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int T,m,a,y,x,p,c;
int map[10][10];
struct BC{
    int y;
    int x;
    int c;
    int p;
    BC(int y, int x, int c, int p):y(y),x(x),c(c),p(p){}
};
bool CMP(BC b1, BC b2){
    if(b1.p > b2.p)return true;
    return false;
}

int dy[5]={0,-1,0,1,0};
int dx[5]={0,0,1,0,-1};

void spreadBC(int y, int x, int th,int c){
    for(int i = 0;i<c;i++){
        for(int j= x-i;j<=x+i;j++){
            int ny = y-c+1+i;
            if( ny<0 || ny>=10 || j<0 || j>=10)continue;
            map[ny][j]|=(1<<th);
        }
    }
    for(int i=c-2; i>=0; i--){
        for(int j= x-i; j<=x+i;j++){
            int ny = y+c-1-i;
            if( ny<0 || ny>=10 || j<0 || j>=10)continue;
            map[ny][j]|=(1<<th);
        }
    }
}

vector<BC> list;
vector<int> dir[2];
vector<int> output[2];

int main(){
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        memset(map,0,sizeof(map));
        dir[0].clear();
        dir[1].clear();
        output[0].clear();
        output[0].clear();
        list.clear();
        cin>>m>>a;
        dir[0].resize(m);
        dir[1].resize(m);
        output[0].resize(m+1);
        output[1].resize(m+1);
        for(int i=0; i<2;i++){
            for(int j=0; j<m;j++){
                cin>>dir[i][j];
            }
        }
        for(int i=0; i<a;i++){
            cin>>x>>y>>c>>p;
            list.push_back(BC(y-1,x-1,c,p));
        }
        sort(list.begin(),list.end(),CMP);
        for(int i=0; i<a;i++){
            spreadBC(list[i].y,list[i].x,i,list[i].c+1);
        }
        
        int ay = 0;
        int ax = 0;
        int by= 9;
        int bx=9;
        for(int i=0; i<m+1;i++){
            output[0][i]=map[ay][ax];
            output[1][i]=map[by][bx];
            ay += dy[dir[0][i]];
            ax += dx[dir[0][i]];
            by += dy[dir[1][i]];
            bx += dx[dir[1][i]];
        }
        
        int sum=0;
        for(int i=0; i<m+1;i++){
            if(output[0][i]!=0 && output[1][i]!=0){
                // 이거 처리를 해보쟈
                int arr[2]={0,};
                arr[0]=output[0][i];
                arr[1]=output[1][i];
                int minAns=0;
                int last=0;
                for(int th=0; th<a;th++){
                    if((arr[0]&(1<<th))){
                        last=th;
                        minAns+=list[th].p;
                        break;
                    }
                }
                for(int th=0; th<a;th++){
                    if((last!=th) && (arr[1]&(1<<th))){
                        minAns+=list[th].p;
                        break;
                    }
                }
                swap(arr[0],arr[1]);
                int minAns2=0;
                last=0;
                for(int th=0; th<a;th++){
                    if((arr[0]&(1<<th))){
                        last=th;
                        minAns2+=list[th].p;
                        break;
                    }
                }
                for(int th=0; th<a;th++){
                    if((last!=th) && (arr[1]&(1<<th))){
                        minAns2+=list[th].p;
                        break;
                    }
                }
                sum+=max(minAns2,minAns);
            }else if(output[0][i]==0 && output[1][i]!=0){
                for(int th=0; th<a;th++){
                    if(output[1][i]&(1<<th)){
                        
                        sum+=list[th].p;
                        break;
                    }
                }
            }else if(output[0][i]!=0 && output[1][i]==0){
                for(int th=0; th<a;th++){
                    if(output[0][i]&(1<<th)){
                        
                        sum+=list[th].p;
                        break;
                    }
                }
                
            }
        }
        cout<<"#"<<tc<<" "<<sum<<endl;
    }
}
