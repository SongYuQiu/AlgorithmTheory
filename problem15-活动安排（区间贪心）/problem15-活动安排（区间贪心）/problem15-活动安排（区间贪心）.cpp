//
//  main.cpp
//  problem15-活动安排（区间贪心）
//
//  Created by JustforStar on 2021/12/1.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=100;

struct Inteval{
    int start,end;
}I[maxn];

bool cmp(Inteval a,Inteval b){
    if(a.start!=b.start) return a.start>b.start;
    else return a.end<b.end;
}

int main(int argc, const char * argv[]) {
    int n;
    printf("请输入活动数量n:");
    while(scanf("%d",&n) && n!=0){
        printf("请输入%d个活动的开始和结束时间：\n",n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&I[i].start,&I[i].end);
        }
        sort(I,I+n,cmp);
        
        int ans=1,lastS=I[0].start;
        for(int i=1;i<n;i++){
            if(I[i].end<=lastS){
                lastS=I[i].start;
                ans++;
            }
        }
        printf("最多可以安排%d个活动\n",ans);
        printf("请输入活动数量n:");
    }
    return 0;
}
