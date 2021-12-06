//
//  main.cpp
//  problem81-Dijkstra单源边权相等最短路径
//
//  Created by JustforStar on 2021/12/5.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXV = 100;
const int INF = 10000000;
int G[MAXV][MAXV];
int n,m,s;
int vis[MAXV]={false};
int d[MAXV];

void Dijkstra(int s){
    fill(d, d+n, INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[u]+1<d[j]&&G[u][j]!=INF){
                d[j]=d[u]+1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int u,v;
    scanf("%d%d%d",&n,&m,&s);
    fill(G[0], G[0]+MAXV*MAXV, INF);
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        G[u][v]=1;
    }
    Dijkstra(s);
    for(int i=0;i<n;i++){
        printf("%d ",d[i]);
    }
    printf("\n");
    return 0;
}
