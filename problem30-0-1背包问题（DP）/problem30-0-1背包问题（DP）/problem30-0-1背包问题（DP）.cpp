//
//  main.cpp
//  1背包问题（DP）
//
//  Created by JustforStar on 2021/12/1.
//

#include <iostream>

int MAX(int a,int b){
    return a>b?a:b;
}

int main(int argc, const char * argv[]) {
    
    int w[1000],c[1000],dp[1000],V,n;
    
    printf("请输入物品的种类n：");
    scanf("%d",&n);
    printf("请输入背包的容量V：");
    scanf("%d",&V);
    
    printf("请输入%d个物品的重量：",n);
    for (int i=0; i<n; i++) {
        scanf("%d",&w[i]);
    }
    printf("请输入%d个物品的价值：",n);
    for (int i=0; i<n; i++) {
        scanf("%d",&c[i]);
    }
    
    //动态规划边界
    for(int i=0;i<=V;i++){
        dp[i]=0;
    }
    
    //动态转移
    for(int i=0;i<n;i++){
        for(int j=V;j>=w[i];j--){
            dp[j]=MAX(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    
    int res=-1;
    for(int i=0;i<=V;i++){
        if(dp[i]>res){
            res=dp[i];
        }
    }
    
    printf("背包最大的价值为%d\n",res);
    
    return 0;
}
