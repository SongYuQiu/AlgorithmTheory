//
//  main.cpp
//  problem13-连续最大子序列和
//
//  Created by JustforStar on 2021/12/1.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int num[1000],maxS=-1,dp[1000],n;
    printf("请输入数字序列的长度n：");
    scanf("%d",&n);
    printf("请输入%d个数字：",n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    dp[0]=num[0];
    maxS=num[0];
    int start=0,end=0;
    for(int i=1;i<n;i++){
        int flag=0;//标记开始位置是否改变
        if(dp[i-1]+num[i]>num[i]){
            dp[i]=dp[i-1]+num[i];
        }else{
            dp[i]=num[i];
            flag=1;
        }
        if(dp[i]>maxS){
            if(flag){
                start=i;
            }
            end=i;
            maxS=dp[i];
        }
    }
    
    printf("最大子序列和为%d\n",maxS);
    printf("子序列为：");
    for(int i=start;i<=end;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    
    return 0;
}
