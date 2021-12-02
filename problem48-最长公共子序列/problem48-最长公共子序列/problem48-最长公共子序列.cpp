//
//  main.cpp
//  problem48-最长公共子序列
//
//  Created by JustforStar on 2021/12/2.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    char A[1000],B[1000];
    int n,m;
    int dp[1000][1000];
    
    printf("请输入A：");
    gets(A+1);
    
    printf("请输入B：");
    gets(B+1);
    
    n=(int)strlen(A+1);
    m=(int)strlen(B+1);
    
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=0;i<=m;i++)
        dp[0][i]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
        }
    }
    
    printf("最长公共子序列的长度为%d。\n",dp[n][m]);
    
    return 0;
}
