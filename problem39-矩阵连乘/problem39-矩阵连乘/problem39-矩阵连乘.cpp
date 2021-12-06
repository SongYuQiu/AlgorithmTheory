//
//  main.cpp
//  problem39-矩阵连乘
//
//  Created by JustforStar on 2021/12/6.
//

//p[]存储N个矩阵的行列数，长度为N+1，对于第i个矩阵，它的行列数为别为p[i-1]和p[i]
//m[i][j]表示矩阵Ai到矩阵Aj的最优解
//m[i][i]=0因为单独一个矩阵不需要进行任何乘法计算
//m[i][j]=min { m[i][k]+m[k+1][j]+pi-1pkpj } 状态转移方程
//从矩阵链的长度l为2开始遍历，最长为N
//若需要记录组合的情况，用s[][]来记录

#include <iostream>

#define MAXN 1000
#define INF 10000000

void PrintK(int s[MAXN][MAXN],int i,int j){
    //打印Ai到Aj矩阵链的分组方案
    if(i==j){
        printf("A%d",i);
        return;
    }
    else{
        printf("(");
        PrintK(s, i, s[i][j]);
        PrintK(s, s[i][j]+1, j);
        printf(")");
    }
}

int main(int argc, const char * argv[]) {
    int p[MAXN];
    int m[MAXN][MAXN];
    int s[MAXN][MAXN];
    int n;
    
    printf("请输入矩阵的数量n：");
    scanf("%d",&n);
    printf("请输入%d个矩阵的行列数：",n);
    for (int i=0; i<=n; i++) {
        scanf("%d",&p[i]);
        m[i][i]=0;//矩阵链长度为1的情况下，计算量为0
    }
    
    //矩阵链长度从2开始计算，最长为n，因为有n个矩阵
    for(int l=2;l<=n;l++){
        //长度为j的矩阵从A1开始，最多到A(n-l+1)
        for(int j=1;j<=n-l+1;j++){
            //从Aj开始的长度为l的矩阵链的末尾序号为j+l-1，矩阵链为AjA(j+l-1)
            int end=j+l-1;
            m[j][end]=INF;
            //这里的k一定是从j开始的，k遍历的是中间断开的位置
            for(int k=j;k<end;k++){
                int temp = m[j][k]+m[k+1][end]+p[j-1]*p[k]*p[end];
                if(temp<m[j][end]){
                    m[j][end]=temp;
                    s[j][end]=k;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    PrintK(s, 1, n);
    printf("最少为：%d\n",m[1][n]);
    return 0;
}
