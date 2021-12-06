//
//  main.cpp
//  problem17-连续邮资
//
//  Created by JustforStar on 2021/12/6.
//

#include <iostream>
using namespace std;

#define MAXN 100
#define INF 100000000

int n;//邮票面值数
int m;//允许的最多邮票张数
int nown;//当前搜索的邮票种类
int maxStamp;//当前最大邮资
int x[MAXN];//当前邮票的邮资情况
int c[MAXN][MAXN];//记录当前状态 c[i][j]用前i种邮票刚好凑成j邮资所需要的最少的邮票数
int best[MAXN];//最终的最优的结果

int findMax(){
    //向下更新数据，就是在前nown中邮票的基础上，结合当前第nown张邮票，更新c[nown][j]的值，j从1-maxStamp
    int j=1;
    while(c[nown-1][j]!=0){
        //若当前的票面x[nown]大于j，则直接拿c[nown-1][j]的值
        //若当前的票面x[nown]小于j，但是c[nown-1][j-x[nown]]+1 >= c[nown-1][j]，则直接拿c[nown-1][j]的值
        if(x[nown]>j||c[nown-1][j-x[nown]]+1 >= c[nown-1][j]){
            c[nown][j]=c[nown-1][j];
        }else{
            c[nown][j]=c[nown-1][j-x[nown]]+1;
        }
        j++;
    }
    
    //此时的j是当前的最大邮资区间+1
    //向右更新数据，就是扩展最大邮资区间了
    while(true){
        int temp=INF;
        for(int i=1;i<=nown;i++){
            //比较当下 假设所使用的最后一张邮票的面值为x[i]（在数量上需要1） 那么还需要的张数就等于 c[nown][j-x[i]]
            //取最小值更新最新的总邮资 c[nown][j]
            if(temp>c[nown][j-x[i]]+1){
                temp=c[nown][j-x[i]]+1;
            }
        }
        if(temp==INF || temp>m){
            break;//说明到底了 已经开始不连续了
        }else{
            c[nown][j]=temp;
        }
        j++;
    }
    c[nown][j]=0;
    return j-1;
}

void DFS(){
    if(nown==n){
        //如果正搜索的邮票的种类数为n
        if(x[nown]*m<maxStamp){
            //如果当前的最大的邮票使用了m张的总邮资还是比当前的maxStamp小，直接剪枝，后面的不需要再判断了
            return;
        }
        //否则算出当前的最大邮资与maxStamp比较
        int temp=findMax();
        if(temp>maxStamp){
            maxStamp=temp;
            for(int i=0;i<=n;i++){
                best[i]=x[i];
            }
        }
    }else{
        //如果还没有搜索到最底层，那么算出当前的最大值用于限制下一张邮票的邮资上限，然后继续搜索
        int temp=findMax();
        for(int j=x[nown]+1;j<=temp+1;j++){
            x[++nown]=j;//更新下一层邮票的邮资;
            DFS();
            nown--;//回溯记得恢复
        }
    }
}


int main(int argc, const char * argv[]) {
    x[0]=0;
    x[1]=1;
    nown=1;
    printf("请输入n和m的值：");
    scanf("%d%d",&n,&m);
    DFS();
    printf("最大的邮资值为：%d\n",maxStamp);
    for(int i=1;i<=n;i++){
        printf("%d ",best[i]);
    }
    printf("\n");
    return 0;
}
