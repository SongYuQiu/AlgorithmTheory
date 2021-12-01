//
//  main.cpp
//  problem65-0-1背包问题（回溯优化剪枝）
//
//  Created by JustforStar on 2021/12/1.
//

#include <iostream>
int w[1000],v[1000],x[1000]={0},c,n;//x[i]用来标记物品是否被选
int cw,cv;//当前背包重量，当前背包价值
int bestv,bestx[1000]={0};//最优背包价值

// 冒泡排序
void Sort(int n,int *w,int*v){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if( (float(v[j])/float(w[j])) < (float(v[j+1])/float(w[j+1])) ){
                int tempw = w[j];
                int tempv = v[j];
                w[j] = w[j+1];
                v[j] = v[j+1];
                w[j+1] = tempw;
                v[j+1] = tempv;
            }
        }
    }
}

//计算当前背包的价值与剩余物品的总价值的和
int bound(int index){
    int tempv=cv;
    int j = index+1;
    int leftw = c-cw;
    while(j<n&&leftw>=w[j]){
        leftw-=w[j];
        tempv+=v[j];
        j++;
    }
    if(j<n){
        tempv+=leftw*float(v[j+1])/float(w[j+1]);
    }
    return tempv;
}

void knapsack(int index){
    if(index>=n){
        //到达叶子节点 判断是否是最优的
        if(cv>bestv){
            bestv=cv;
            for(int i=0;i<n;i++){
                bestx[i]=x[i];
            }
        }
    }else{
        //当前背包的重量+w[index]要小于等于背包总容量才进入左子树
        if(cw+w[index]<=c){
            cw+=w[index];
            cv+=v[index];
            x[index]=1;
            knapsack(index+1);
            //一定要复原回溯
            cw-=w[index];
            cv-=v[index];
            x[index]=0;
        }
        //当前背包的总价值+ index+1及以后的所有物品的总价值 大于当前最优总价值才进入右子树
        if(bound(index)>bestv){
            x[index]=0;
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
    
    Sort(n, w, v);
    
    knapsack(0);
    printf("排序后的物品顺序为:\n");
    for(int i=0;i<n;i++){
        printf("第%d个物品的重量为%d，价值为%d；\n",i+1,w[i],v[i]);
    }
    printf("最优总价值为%d\n",bestv);
    for(int i=0;i<n;i++){
        printf("%d ",bestx[i]);
    }
    printf("\n");
    
    return 0;
}
