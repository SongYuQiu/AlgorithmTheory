//
//  main.cpp
//  problem36-数塔动态规划
//
//  Created by JustforStar on 2021/11/22.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int f[maxn][maxn],dp[maxn][maxn];

void print_result(int n)
{
//    cout << "最大路径和：" << dp[1][1] << '\n';
    int node_value;
    // 首先输出塔顶元素
    cout << "最大路径：" << f[1][1];
    int j = 1;
    for (int i = 1; i < n; ++i)
    {
        node_value = dp[i][j] - f[i][j];
        /* 如果node_value == dp[i+1][j]则说明下一步应该是data[i+1][j]；
         如果node_value == dp[i+1][j+1]则说明下一步应该是data[i+1][j+1]*/
        if (node_value == dp[i+1][j+1]) ++j;
        cout << "->" << f[i+1][j];
    }
    cout << endl;
}

int main(){
    int n;
    printf("请输入数塔的层数n：");
    scanf("%d",&n);
    printf("请输入数塔的形状:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&f[i][j]);//输入数塔
        }
    }
    //边界
    for(int j=1;j<=n;j++){
        dp[n][j]=f[n][j];
    }
    //从第n-1层不断往上计算出dp[i][j]
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            //状态转移方程
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+f[i][j];
        }
    }
    printf("结果为：%d\n",dp[1][1]);
    print_result(n);
    return 0;
}
