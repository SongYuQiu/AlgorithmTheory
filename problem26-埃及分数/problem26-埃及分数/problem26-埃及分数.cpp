//
//  main.cpp
//  problem26-埃及分数
//
//  Created by JustforStar on 2021/12/6.
//

#include <iostream>

void Egyptian(int a,int b){
    printf("%d/%d=",a,b);
    while(true){
        if(b%a==0){
            b=b/a;
            a=1;
        }
        if(a==1){
            printf("%d/%d\n",a,b);
            break;
        }else{
            //记录原始a b值
            int oa=a,ob=b;
            //b除a的余数+1作为新的埃及分数的分母
            int nb=b/a+1;
            printf("%d/%d+",1,nb);
            //更新新的需要拆分的埃及分数
            a=oa-ob%oa;
            b=ob*nb;
        }
    }
}

int main(int argc, const char * argv[]) {
    int a,b;
    printf("请输入分数的分子a和分母b：");
    scanf("%d%d",&a,&b);
    Egyptian(a, b);
    return 0;
}
