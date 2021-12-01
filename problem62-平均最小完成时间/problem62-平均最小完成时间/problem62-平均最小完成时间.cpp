//
//  main.cpp
//  problem62-平均最小完成时间
//
//  Created by JustforStar on 2021/12/1.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int time[100],n,res,count=0,stop[100]={0};
    printf("请输入活动的数量n：");
    scanf("%d",&n);
    printf("请输入%d个活动的时长：",n);
    for(int i=0;i<n;i++){
        scanf("%d",&time[i]);
        count++;
    }
    sort(time, time+n);
    stop[0]=time[0];
    res=stop[0];
    for(int i=1;i<n;i++){
        stop[i]+=stop[i-1]+time[i];
        res+=stop[i];
    }
    
    printf("最小平均完成时间为：%f\n",float(res)/float(count));
    return 0;
}
