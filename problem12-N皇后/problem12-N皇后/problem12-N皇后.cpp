//
//  main.cpp
//  problem12-N皇后
//
//  Created by JustforStar on 2021/12/2.
//

#include <iostream>

int hashTable[1000]={0},p[1000],n,count=0;

void Nqueen(int index){
    //即将排放第index列
    if(index==n){
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(i-j)==abs(p[i]-p[j])){
                    flag=false;
                }
            }
        }
        if(flag){
            count++;
            printf("--------第%d种排列方案--------\n",count);
            for(int i=0;i<n;i++){
                printf("%d ",p[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(hashTable[i]==0){
            hashTable[i]=1;
            p[index]=i;
            Nqueen(index+1);
            hashTable[i]=0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    printf("请输入皇后的数量n：");
    scanf("%d",&n);
    
    Nqueen(0);
    
    printf("总共有%d种排列方案。\n",count);
    
    return 0;
}
