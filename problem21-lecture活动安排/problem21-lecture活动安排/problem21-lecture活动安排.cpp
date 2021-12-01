//
//  main.cpp
//  problem21-lecture活动安排
//
//  Created by JustforStar on 2021/12/1.
//

#include <iostream>

const int maxn=100;

struct Inteval{
    int start,end;
}I[maxn];

int main(int argc, const char * argv[]) {
    int n;
    int num[maxn];
    printf("请输入活动数量n:");
    while(scanf("%d",&n) && n!=0){
        memset(num, 0, sizeof(num));
        printf("请输入%d个活动的开始和结束时间：\n",n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&I[i].start,&I[i].end);
            for(int j=I[i].start;j<I[i].end;j++){
                num[j]++;
            }
        }
        int res=num[0];
        for(int i=1;i<n;i++){
            if(num[i]>res){
                res=num[i];
            }
        }
        printf("最多需要%d个lecture\n",res);
        printf("请输入活动数量n:");
    }
    return 0;
}
