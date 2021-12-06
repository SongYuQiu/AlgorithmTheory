//
//  main.cpp
//  problem77-城市公交线路设计Floyd
//
//  Created by JustforStar on 2021/12/5.
//

#include <iostream>
#include <cstdio>
using namespace std;

const int INF=1000000000;
const int MAXV=200;
int n,m;//定点数和边数
int dis[MAXV][MAXV];
int path[MAXV][MAXV];

void Floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]&&dis[i][k]!=INF&&dis[k][j]!=INF){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
}

void findPath(int i,int j){
    printf("%d<-",j);
    if(path[i][j]==i){
        printf("%d",i);
        return;
    }
    findPath(i, path[i][j]);
}

int main(int argc, const char * argv[]) {
    int u,v,w;
    fill(dis[0], dis[0]+MAXV*MAXV, INF);
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) {
        dis[i][i]=0;
        for (int j=0; j<n; j++) {
            if(i==j)
                path[i][j]=i;
            else
                path[i][j]=-1;
        }
    }
    //总共m条边
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        dis[u][v]=w;
    }
    
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++) {
            if(dis[i][j]!=INF){
                path[i][j]=i;
            }
        }
    }
    
    
    Floyd();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",dis[i][j]);
        }
        printf("\n");
    }
    
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            printf("%d\t",path[i][j]);
//        }
//        printf("\n");
//    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(path[i][j]==-1)
                continue;
            findPath(i,j);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

