//
//  main.cpp
//  problem78-任务分配（分支限界法）
//
//  Created by JustforStar on 2021/12/5.
//

#include <iostream>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f  //定义无穷大
#define MAXN 21

int n;
int c[MAXN][MAXN]; //人员-任务-成本矩阵
int bestx[MAXN];   //最优分配方案
int mincost=INF;   //最低成本
int  total=1;      //节点个数累计

struct NodeType{
    int no; //结点编号
    //人员编号  按照员工的编号顺序进行考虑的  解空间树 每一层是考虑第i个员工被分配第几个任务
    int i;
    int x[MAXN]; //为人员i分配的任务编号 记录的是所有的员工被分配的任务情况
    bool worker[MAXN]; //worker[i]=true表示任务i已分配
    int cost; //当前分配任务的总成本
    int lb; //下界
    bool operator<(const NodeType& s) const{
        return lb > s.lb;
    }
};

//计算节点的下界
void bound(NodeType& e){
    int minsum=0;
    //计算当前节点的下界，当前是员工e.i，那么就要考虑e.i+1开始往后的员工的最低任务成本作为该节点的下界
    for (int i=e.i+1; i<=n; i++) {
        int minc=INF;
        for(int j=1;j<=n;j++){
            if(e.worker[j]==false&&c[i][j]<minc){
                minc=c[i][j];
            }
        }
        minsum+=minc;
    }
    e.lb=e.cost+minsum;
}

void bfs(){
    int j;
    NodeType e,e1;
    priority_queue<NodeType>qu; //定义一个优先队列
    //初始化 ！！！根节点e！！！ 的x[]的值和worker[]的值
    //因为是根节点 所以当前一个任务都没有分配
    memset(e.x,0,sizeof((e.x)));
    memset(e.worker, 0, sizeof(e.worker));
    
    //求最开始的下界 即每一个员工的最低成本的和
    //将根节点入队列
    e.i=0;
    e.cost=0;
    bound(e);
    e.no=total++;
    qu.push(e);
    
    while (!qu.empty()) {
        e=qu.top();
        qu.pop();
        //如果已经遍历到最后一个员工了，那就判断是不是最优解，是则更新
        if(e.i==n){
            if(e.cost<mincost){
                mincost=e.cost;
                for(j=1;j<=n;j++){
                    bestx[j]=e.x[j];//更新最优的分配策略
                }
            }
        }
        e1.i=e.i+1; //拓展下一层 也就是下一个员工
        for(j=1;j<=n;j++){
            //找尚未分配的任务，若已分配则跳过
            if(e.worker[j])
                continue;
            //找到尚未分配的任务j
            //将上一个节点的员工任务分配状态同步到e1节点
            //员工i所分配到的任务编号x[i]
            for(int i=1;i<=n;i++){
                e1.x[i]=e.x[i];
            }
            //为当前节点的员工（对应编号为e1.i）分配任务j（因为任务j尚未分配）
            e1.x[e1.i]=j;
            //更新任务被分配的状态
            for(int k=1;k<=n;k++){
                e1.worker[k]=e.worker[k];
            }
            e1.worker[j]=true;
            e1.cost = e.cost+c[e1.i][j];
            bound(e1);
            e1.no=total++;
            if(e1.lb<=mincost)
                qu.push(e1);
        }
    }
}


int main(int argc, const char * argv[]) {
    cout << "输入人员数/任务数的大小：n" << endl;
    cin >> n;
    cout << "输入人员-任务成本值("<<n<<"x"<<n<<"矩阵)：" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    bfs();
    printf("最优方案：\n");
    for (int k = 1; k <= n; k++)
        printf("第%d个人员分配第%d个任务\n",k, bestx[k]);
    cout <<"总成本="<< mincost;
    return 0;
}
