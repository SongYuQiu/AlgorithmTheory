//
//  main.cpp
//  problem6-找出两个数和为特定值
//
//  Created by JustforStar on 2021/11/29.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int nums[1000],n,m;
    printf("请输入数组的长度n:");
    scanf("%d",&n);
    printf("请输入数组nums的%d个数字:",n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    printf("请输入指定和m:");
    scanf("%d",&m);
    
    int p=0,q=n-1;
    int flag = 0;
    while(p<q){
        if(nums[p]+nums[q]==m){
            flag=1;
            break;
        }else if(nums[p]+nums[q]<m){
            p++;
        }else{
            q--;
        }
    }
    if(flag){
        printf("%d %d : %d + %d = %d\n",p,q,nums[p],nums[q],m);
    }else{
        printf("不存在一对和为%d的数。\n",m);
    }
    return 0;
}
