//
//  main.cpp
//  problem63-1至9的k个数组合成和为n
//
//  Created by JustforStar on 2021/12/6.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int k;
int sum=0;
int path[100]={0};
int hashTable[100]={false};
int cou=0;
int flag[100]={0};

void backtrack(int depth){
    if(depth==k+1){
        //达到指定数量的数
        if(sum==n){
            int temp[100];
            for(int i=1;i<=k;i++)
                temp[i]=path[i];
            sort(temp+1, temp+k+1);
            
            int ten=10;
            int flagS=0;
            for(int i=1;i<=k;i++){
                flagS+=temp[i]*ten;
                ten*=10;
            }
            
            int tempc=cou;
            while(tempc>=0){
                if(flagS==flag[tempc])
                    return;
                tempc--;
            }
            
            flag[cou++]=flagS;
            for(int i=1;i<=k;i++){
                printf("%d ",temp[i]);
            }
            printf("\n");
            return;
        }
    }
    for(int i=1;i<10;i++){
        if(hashTable[i]==false && sum+i<=n){
            hashTable[i]=true;
            sum+=i;
            path[depth]=i;
            backtrack(depth+1);
            hashTable[i]=false;
            sum-=i;
        }
    }
}

int main(int argc, const char * argv[]) {
    printf("请输入n和k：");
    scanf("%d%d",&n,&k);
    backtrack(1);
    return 0;
}
