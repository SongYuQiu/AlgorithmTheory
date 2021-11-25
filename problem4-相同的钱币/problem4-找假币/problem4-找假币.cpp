//
//  main.cpp
//  problem4-相同的钱币
//
//  Created by JustforStar on 2021/11/23.
//

#include <iostream>

int main() {
    int coins[8];
    printf("请输入8个硬币的重量:");
    for(int i=0;i<8;i++){
        scanf("%d",&coins[i]);
    }
    
    int a=coins[0]+coins[1];
    int b=coins[2]+coins[3];
    
    if(a==b){
        int real = coins[0];
        for(int i=4;i<8;i++){
            if(coins[i]!=real){
                printf("假币是第%d枚硬币\n",i+1);
            }
        }
    }else if(a>b){
        if((coins[0]+coins[2])>(coins[1]+coins[3])){
            //此时假币锁定在coins[0]和coins[3]里面
            if(coins[0]!=coins[2]){
                printf("假币是第1枚硬币\n");
            }else{
                printf("假币是第4枚硬币\n");
            }
        }else{
            if(coins[1]!=coins[0]){
                printf("假币是第2枚硬币\n");
            }else{
                printf("假币是第3枚硬币\n");
            }
        }
    }else{
        if((coins[0]+coins[2])<(coins[1]+coins[3])){
            //此时假币锁定在coins[0]和coins[3]里面
            if(coins[0]!=coins[2]){
                printf("假币是第1枚硬币\n");
            }else{
                printf("假币是第4枚硬币\n");
            }
        }else{
            if(coins[1]!=coins[0]){
                printf("假币是第2枚硬币\n");
            }else{
                printf("假币是第3枚硬币\n");
            }
        }
    }
    
    return 0;
}
