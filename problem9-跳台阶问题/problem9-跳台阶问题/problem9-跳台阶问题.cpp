//
//  main.cpp
//  problem9-跳台阶问题
//
//  Created by JustforStar on 2021/11/29.
//

#include <iostream>

int Res(int i){
    if(i==0||i==1||i==2){
        return i;
    }else{
        return Res(i-1)+Res(i-2);
    }
}


int main(int argc, const char * argv[]) {
    int n;
    printf("请输入台阶的层数n：");
    scanf("%d",&n);
    printf("总共有%d中跳法。\n",Res(n));
    return 0;
}
