//
//  main.cpp
//  1背包问题（回溯法）
//
//  Created by JustforStar on 2021/12/1.
//


//第一步按照物品的单位价值的高低进行排序
//开始回溯算法
//剪枝条件1:当超过容量时，直接不用考虑进入左子树；
//剪枝条件2:当前价值加上剩余价值的和小于当前最优价值时，不用考虑进入右子树
//本代码先写一个比较基础的版本，就是对于剪枝条件2的判断，粗暴的将剩下的都加进去判断，不对物品进行排序

#include <iostream>

int w[1000],v[1000],c,n;
int cw,cv;//当前背包重量，当前背包价值
int bestv;//最优背包价值

//计算当前背包的价值与剩余物品的总价值的和
int bound(int index){
    int temp=cv;
    for(int i=index+1;i<n;i++){
        temp+=v[index];
    }
    return temp;
}

void knapsack(int index){
    if(index>=n){
        //到达叶子节点 判断是否是最优的
        if(cv>bestv){
            bestv=cv;
        }
    }else{
        //当前背包的重量+w[index]要小于等于背包总容量才进入左子树
        if(cw+w[index]<=c){
            cw+=w[index];
            cv+=v[index];
            knapsack(index+1);
            //一定要复原回溯
            cw-=w[index];
            cv-=v[index];
        }
        //当前背包的总价值+ index+1及以后的所有物品的总价值 大于当前最优总价值才进入右子树
        if(bound(index)>bestv){
            knapsack(index+1);
        }
    }
}

int main(int argc, const char * argv[]) {

    printf("请输入物品的种类n：");
    scanf("%d",&n);
    printf("请输入背包的容量c：");
    scanf("%d",&c);
    
    printf("请输入%d个物品的重量：",n);
    for (int i=0; i<n; i++) {
        scanf("%d",&w[i]);
    }
    printf("请输入%d个物品的价值：",n);
    for (int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }
    
    knapsack(0);
    printf("最优总价值为%d\n",bestv);
    
    return 0;
}
