//
//  main.cpp
//  problem56-最长不下降子序列
//
//  Created by JustforStar on 2021/12/2.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int nums[1000],dp[1000],n,ans=-1,p[1000]={0},flag=0;
    
    printf("请输入nums的数量n：");
    scanf("%d",&n);
    printf("请输入%d个数字：",n);
    for (int i=0; i<n; i++) {
        scanf("%d",&nums[i]);
    }
    
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(nums[i]>=nums[j]&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                p[i]=j;
            }
        }
        if(dp[i]>ans){
            ans=dp[i];
            flag=i;
        }
    }
    
    printf("最长不下降子序列的长度为%d\n",ans);
    
    int res[100],index=0,tempans=ans;
    
    while(tempans){
        res[index]=nums[flag];
        flag=p[flag];
        tempans--;
        index++;
    }
    
    for(int i=ans-1;i>=0;i--){
        printf("%d ",res[i]);
    }
    printf("\n");
    
    return 0;
}
