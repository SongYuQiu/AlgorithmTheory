//
//  main.cpp
//  pproblem54-8皇后（回溯）
//
//  Created by JustforStar on 2021/12/2.
//

#include <iostream>

int hashTable[1000]={0},p[1000],n,count=0;

void Nqueen(int index){
    //即将排放第index列
    if(index==n){
        count++;
        printf("--------第%d种排列方案--------\n",count);
        for(int i=0;i<n;i++){
            printf("%d ",p[i]);
        }
        printf("\n");
        return;
    }
    for(int x=0;x<n;x++){
        bool flag=true;
        if(hashTable[x]==0){
            //第x行还没有入排列，还没有放皇后
            for(int i=0;i<index;i++){
                //第index列的皇后行号为x，第i列的皇后行号为p[i]
                if(abs(i-index)==abs(p[i]-x)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                p[index]=x;
                hashTable[x]=1;
                Nqueen(index+1);
                hashTable[x]=0;
            }
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
