//
//  main.cpp
//  problem41-lecture活动安排（真正的贪心）
//
//  Created by JustforStar on 2021/12/1.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a<b;
}

int main(int argc, const char * argv[]) {
    int start[100],end[100],n;
    printf("请输入活动的数量n:");
    scanf("%d",&n);
    printf("请输入n个活动的开始和结束时间：\n");
    for (int i=0; i<n; i++) {
        scanf("%d%d",&start[i],&end[i]);
    }
    
    sort(start,start+n,cmp);//sort默认升序
    sort(end,end+n,cmp);
    
    int res=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(start[i]<end[j]){
            res++;
        }else{
            j++;
        }
    }
    
    printf("最多需要%d个lecture\n",res);
    
    return 0;
}
